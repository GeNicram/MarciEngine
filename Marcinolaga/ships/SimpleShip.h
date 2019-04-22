#pragma once

#include "ShipBase.h"

#include <entity/Entity.h>
#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

class SimpleShip : public ShipBase
{
public:
	SimpleShip();
	~SimpleShip();
	virtual void Create();

	static void UpdateCallback(EngineObject* object, sf::Time delta_time);
	virtual void Update(sf::Time delta_time);
	void SetLevel(int level);

protected:
	float individual_speed;

};

