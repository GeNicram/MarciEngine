#include "SimpleShip.h"

#include "../scene/CurrentScene.h"
#include "ShipSettings.h"

#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/PositionComponent.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

#include <cassert>

SimpleShip::SimpleShip()
	: individual_speed(0)
{
}


SimpleShip::~SimpleShip()
{
}

extern void PlayerTouched(EngineObject* object, CollideComponent& collide, std::shared_ptr<CollideComponent>& touched);
//{
//	CurrentScene::Get()->HandleCollision(collide.GetOwner(), touched->GetOwner());
//}

void SimpleShip::Create()
{
	 entity = Entity::Create()
		 .AddGraphic("Assets/enemy2.png", 50)
		 .AddPosition(sf::Vector2f(0, 0))
		 .AddScript(UpdateCallback, this)
		 .AddCollide(collide_enemy, sf::Vector2f(128, 128), {collide_player}, PlayerTouched, this);
}

void SimpleShip::UpdateCallback(EngineObject* object, sf::Time delta_time)
{
	SimpleShip* ship = dynamic_cast<SimpleShip*>(object);
	assert(ship);
	if (!ship)
		return;

	ship->Update(delta_time);
}

void SimpleShip::Update(sf::Time delta_time)
{
	auto position = entity.GetComponents(component_type::position);

	auto pos = std::dynamic_pointer_cast<PositionComponent>(position[0]);

	sf::Vector2f move_direction(0.0f, 1.0f);

	pos->Move(individual_speed * delta_time.asSeconds() * move_direction);
}

void SimpleShip::SetLevel(int level)
{
	int speed_factor = std::rand() % static_cast<int>(enemy_speed);
	individual_speed = enemy_speed + 0.01f * level * (speed_factor - enemy_speed/2);
}
