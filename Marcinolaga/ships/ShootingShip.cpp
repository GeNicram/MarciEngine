#include "ShootingShip.h"

#include "ShipSettings.h"
#include "../scene/CurrentScene.h"
#include "../scene/GameplayScene.h"


ShootingShip::ShootingShip()
	: passed_time(sf::Time::Zero)
{
}


ShootingShip::~ShootingShip()
{
}

void ShootingShip::Update(sf::Time delta_time)
{
	SimpleShip::Update(delta_time);

	if (passed_time.asSeconds() >= 2)
	{
		auto new_bullet = ShootBullet(false, GetPosition() + sf::Vector2f(64, 128),
			enemy_bullet_speed * sf::Vector2f(0.0f, 1.0f));

		if (new_bullet)
		{
			GameplayScene& scene = dynamic_cast<GameplayScene&>(*CurrentScene::Get());
			auto& bullet_container = scene.GetBulletContainer();

			bullet_container.emplace(bullet_container.end(), new_bullet.release());

			passed_time = sf::Time::Zero;
		}

	}
	else
		passed_time += delta_time;
}

void PlayerTouched(EngineObject* object, CollideComponent& collide, std::shared_ptr<CollideComponent>& touched)
{
	CurrentScene::Get()->HandleCollision(collide.GetOwner(), touched->GetOwner());
}

void ShootingShip::Create()
{
	 entity = Entity::Create()
		 .AddGraphic("Assets/enemy1.png", 50)
		 .AddPosition(sf::Vector2f(0, 0))
		 .AddScript(UpdateCallback, this)
		 .AddCollide(collide_enemy, sf::Vector2f(128, 128), {collide_player}, PlayerTouched, this);

	 SetCannonCoolDown(sf::seconds(0.1f));
}
