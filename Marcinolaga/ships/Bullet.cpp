#include "Bullet.h"

#include "ShipSettings.h"
#include "../scene/CurrentScene.h"

#include <iostream>

void coll_test(EngineObject* object, CollideComponent& collide, std::shared_ptr<CollideComponent>& touched)
{
	CurrentScene::Get()->HandleCollision(collide.GetOwner(), touched->GetOwner());
}

Bullet::Bullet(bool player_bullet)
{
	entity = Entity::Create()
		.AddCircle(5,
			player_bullet ? sf::Color::White : sf::Color::Red,
			player_bullet ? ship_layers::player_bullet : ship_layers::enemy_bullet)
		.AddPosition(sf::Vector2f(0, 0))
		.AddCollide(
			player_bullet ? collide_player_bullet : collide_enemy_bullet,
			sf::Vector2f(5, 5),
			{ player_bullet ? collide_enemy : collide_player, },
			coll_test, this);
}

Bullet::Bullet(const Bullet& other)
{
	direction = other.direction;
	entity = other.entity;
}

Bullet::~Bullet()
{
	int a = 0;
}
