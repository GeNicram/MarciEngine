#pragma once
#include "ShipBase.h"

class Bullet : public ShipBase
{
public:
	Bullet() = delete;
	Bullet(bool player_bullet);
	Bullet(const Bullet& other);
	~Bullet();
	sf::Vector2f direction;
};

