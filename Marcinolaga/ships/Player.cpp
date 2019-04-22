#include "Player.h"

#include "../scene/CurrentScene.h"
#include "../scene/GameplayScene.h"
#include "ShipSettings.h"

#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/PositionComponent.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

#include <cassert>

Player::Player()
	: buttons_state{ButtonsState::unknown}
	, passed_time(sf::Time::Zero)
{
	 entity = Entity::Create()
		 .AddGraphic("Assets/player.png", 100)
		 .AddPosition(sf::Vector2f(400, 700))
		 .AddControl({ sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Left, sf::Keyboard::Right },
			InputEventCallback, this)
		 .AddControl({ sf::Keyboard::Space }, ShootCallback, this)
		 .AddScript(MovePlayerCallback, this)
		 .AddCollide(collide_player, sf::Vector2f(128, 128), {}, nullptr, nullptr);

	 SetCannonCoolDown(sf::seconds(0.1f));
}


Player::~Player()
{
}

void Player::InputEventCallback(EngineObject* object, const sf::Event& event)
{
	Player* player = dynamic_cast<Player*>(object);
	assert(player);
	if (!player)
		return;

	player->InputEvent(event);
}

void Player::InputEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Up:
				buttons_state.up = ButtonsState::pressed;
				break;
			case sf::Keyboard::Down:
				buttons_state.down = ButtonsState::pressed;
				break;
			case sf::Keyboard::Left:
				buttons_state.left = ButtonsState::pressed;
				break;
			case sf::Keyboard::Right:
				buttons_state.right = ButtonsState::pressed;
				break;
		}

	} else if (event.type == sf::Event::KeyReleased)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Up:
				buttons_state.up = ButtonsState::released;
				break;
			case sf::Keyboard::Down:
				buttons_state.down = ButtonsState::released;
				break;
			case sf::Keyboard::Left:
				buttons_state.left = ButtonsState::released;
				break;
			case sf::Keyboard::Right:
				buttons_state.right = ButtonsState::released;
				break;
		}
	}
}

void Player::ShootCallback(EngineObject* object, const sf::Event& event)
{
	Player* player = dynamic_cast<Player*>(object);
	assert(player);
	if (!player)
		return;

	player->Shoot(event);
}

void Player::Shoot(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
		buttons_state.trigger = ButtonsState::pressed;
	else if (event.type == sf::Event::KeyReleased)
		buttons_state.trigger = ButtonsState::released;
}

void Player::MovePlayerCallback(EngineObject* object, sf::Time delta_time)
{
	Player* player = dynamic_cast<Player*>(object);
	assert(player);
	if (!player)
		return;

	player->MovePlayer(delta_time);
}

void Player::MovePlayer(sf::Time delta_time)
{
	passed_time += delta_time;
	auto position = entity.GetPositionComponent();

	sf::Vector2f move_direction(
		buttons_state.right == ButtonsState::pressed ? 1.0f : buttons_state.left == ButtonsState::pressed ? -1.0f : 0.0f,
		buttons_state.down == ButtonsState::pressed ? 1.0f : buttons_state.up == ButtonsState::pressed ? -1.0f : 0.0f);


	position->Move(player_speed * delta_time.asSeconds() * move_direction);

	if (buttons_state.trigger == ButtonsState::pressed && last_shot + cool_down < passed_time)
	{
		auto new_bullet = ShootBullet(true, entity.GetPositionComponent()->GetPosition() + sf::Vector2f(64, 0),
			sf::Vector2f(0, -player_bullet_speed));

		if (new_bullet)
		{
			GameplayScene& scene = dynamic_cast<GameplayScene&>(*CurrentScene::Get());
			auto& bullet_container = scene.GetBulletContainer();

			bullet_container.emplace(bullet_container.end(), new_bullet.release());

			last_shot = passed_time;
		}
	}
}
