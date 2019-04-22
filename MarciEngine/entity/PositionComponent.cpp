#include "PositionComponent.h"



PositionComponent::PositionComponent(Entity& owner)
	: Component(owner)
{
}

PositionComponent::~PositionComponent()
{
}

component_type PositionComponent::GetType()
{
	return component_type::position;
}

const sf::Vector2f& PositionComponent::GetPosition() const
{
	return current_position;
}
void PositionComponent::SetPosition(sf::Vector2f position)
{
	current_position = position;
}

void PositionComponent::Move(sf::Vector2f direction)
{
	current_position += direction;
}
