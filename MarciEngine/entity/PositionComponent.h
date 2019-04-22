#pragma once
#include "Component.h"

#include <SFML/System/Vector2.hpp>

class PositionComponent :
	public Component
{
public:
	~PositionComponent();
	virtual component_type GetType() override;

	const sf::Vector2f& GetPosition() const;
	void SetPosition(sf::Vector2f position);
	void Move(sf::Vector2f direction);

private:
	PositionComponent(Entity& owner);
	sf::Vector2f current_position;

	friend class PositionManager;
};

