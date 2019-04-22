#pragma once

#include "../scene/Scene.h"

#include <EngineObject.h>
#include <entity/Entity.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

class ShipBase :
	public EngineObject
{
public:
	ShipBase();
	~ShipBase();
	const sf::Vector2f GetPosition();
	void SetPosition(const sf::Vector2f& position);
	const Entity& GetEntity() const;
protected:
	Entity entity;
};

