#include "Cannon.h"



Cannon::Cannon()
	: last_shot(sf::Time::Zero)
{
}


Cannon::~Cannon()
{
}

void Cannon::SetCannonCoolDown(const sf::Time& cool_down_time)
{
	cool_down = cool_down_time;
}

std::unique_ptr<Bullet> Cannon::ShootBullet(bool player_bullet, const sf::Vector2f& position, const sf::Vector2f& direction)
{
	std::unique_ptr<Bullet> bullet(new Bullet(player_bullet));
	bullet->direction = direction;
	bullet->SetPosition(position);

	return bullet;
}