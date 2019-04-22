#pragma once

#include "ShipBase.h"
#include "Bullet.h"
#include "Cannon.h"

#include <entity/Entity.h>
#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

class Player : public ShipBase, private Cannon
{
public:
	Player();
	~Player();

	static void InputEventCallback(EngineObject* object, const sf::Event& event);
	void InputEvent(const sf::Event& event);
	static void ShootCallback(EngineObject* object, const sf::Event& event);
	void Shoot(const sf::Event& event);
	static void MovePlayerCallback(EngineObject* object, sf::Time delta_time);
	void MovePlayer(sf::Time delta_time);

private:
	struct ButtonsState {
		enum state {unknown, pressed, released};
		state up, down, left, right;
		state trigger;
	};

	ButtonsState buttons_state;

	sf::Time passed_time;
};

