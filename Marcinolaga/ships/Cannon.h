#pragma once

#include "Bullet.h"

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>

class Cannon
{
public:
	Cannon();
	~Cannon();
	void UpdateBullets(const sf::Time& delta_time);
	std::unique_ptr<Bullet> ShootBullet(bool player_bullet, const sf::Vector2f& position, const sf::Vector2f& direction);
	void SetCannonCoolDown(const sf::Time& cool_down_time);
	void SetBulletArea(const sf::IntRect& area);
protected:
	sf::Time cool_down;
	sf::Time last_shot;
};

