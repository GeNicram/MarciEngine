#include "GameplayScene.h"

#include "../ships/ShipSettings.h"

#include <EngineObject.h>
#include <entity/PositionComponent.h>
#include <entity/ScriptComponent.h>

#include <cassert>
#include <iostream>
#include <math.h>

GameplayScene::GameplayScene()
	: passed_time(sf::Time::Zero)
	, last_enemy_spawn(sf::Time::Zero)
	, current_level(0)
	, player_lives(player_max_lives)
	, player_respawn(sf::Time::Zero)
{
	enemy_spawn = Entity::Create().AddScript(Scene::UpdateCallback, this);

	player.reset(new Player());
}

GameplayScene::~GameplayScene()
{
}

void GameplayScene::SetGameArea(const sf::IntRect area)
{
	game_area = area;

	background = Entity::Create()
		.AddPosition(sf::Vector2f(area.left, area.top))
		.AddRectangle(area.width, area.height, sf::Color::Blue, 0);

	bullet_area = area;

	SpawnEnemy();
}

void GameplayScene::Update(sf::Time delta_time)
{
	passed_time += delta_time;

	if (last_enemy_spawn.asSeconds() + 1 < passed_time.asSeconds())
	{
		last_enemy_spawn = passed_time;
		SpawnEnemy();
	}

	current_level = passed_time.asSeconds() / level_up_per_seconds;

	for (auto enemy = enemies.begin(); enemy != enemies.end();)
	{
		if ((*enemy)->GetPosition().y > game_area.top + game_area.height)
		{
			enemy = enemies.erase(enemy);
		}
		else
			++enemy;
	}

	if (!player)
	{
		player_respawn -= delta_time;
		if (player_respawn.asSeconds() <= 0)
			player.reset(new Player());
	}

	UpdateBullets(delta_time);
}

void GameplayScene::UpdateBullets(const sf::Time& delta_time)
{
	for (auto bullet = bullets.begin(); bullet != bullets.end();)
	{
		if (bullet_area.contains(sf::Vector2i((*bullet)->GetPosition())))
		{
			(*bullet)->SetPosition((*bullet)->GetPosition() + delta_time.asSeconds() * (*bullet)->direction);
			++bullet;
		}
		else
			bullet = bullets.erase(bullet);
	}

	passed_time += delta_time;
}

void GameplayScene::SpawnEnemy()
{
	SimpleShip& enemy = **enemies.emplace(enemies.end(), (std::rand() % 2 ? new SimpleShip() : new ShootingShip()));
	enemy.Create();
	enemy.SetLevel(current_level);

	float factor = static_cast<float>(std::rand())/RAND_MAX;
	int rand_result = factor*game_area.width;
	enemy.SetPosition(sf::Vector2f(game_area.left + rand_result, game_area.top));
}

void GameplayScene::HandleCollision(Entity* collide, Entity* touched)
{
	if (&player->GetEntity() == touched)
	{
		player.reset(nullptr);
		player_respawn = sf::seconds(player_respawn_time);
		player_lives--;
		if (player_lives <= 0)
			current_operation = to_summary;
		return;
	}

	for (auto enemy = enemies.begin(); enemy != enemies.end(); ++enemy)
	{
		if (&(*enemy)->GetEntity() == touched)
		{
			enemies.erase(enemy);
			return;
		}
	}
}

std::vector<std::unique_ptr<Bullet>>& GameplayScene::GetBulletContainer()
{
	return bullets;
}
