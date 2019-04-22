#pragma once

#include "SimpleShip.h"
#include "Cannon.h"

class ShootingShip : public SimpleShip, public Cannon
{
public:
	ShootingShip();
	~ShootingShip();
	virtual void Create();

	virtual void Update(sf::Time delta_time);
private:
	sf::Time passed_time;
};

