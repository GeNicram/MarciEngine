#pragma once
#include "Scene.h"
#include "../ships/Player.h"
#include "../ships/SimpleShip.h"
#include "../ships/ShootingShip.h"

#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

class GameplayScene : public Scene
{
public:
	GameplayScene();
	virtual ~GameplayScene();

	void SetGameArea(const sf::IntRect area);
	virtual void Update(sf::Time delta_time) override;
	virtual void HandleCollision(Entity* collide, Entity* touched) override;
	std::vector<std::unique_ptr<Bullet>>& GetBulletContainer();

private:
	std::unique_ptr<Player> player;
	int player_lives;
	sf::Time player_respawn;
	Entity enemy_spawn;
	Entity background;

	std::vector<std::unique_ptr<SimpleShip>> enemies;
	std::vector<std::unique_ptr<Bullet>> bullets;
	sf::IntRect bullet_area;
	void UpdateBullets(const sf::Time& delta_time);

	sf::IntRect game_area;

	sf::Time passed_time;
	sf::Time last_enemy_spawn;

	void SpawnEnemy();

	int current_level;
};

