#include "CollideComponent.h"

#include "Entity.h"

#include <SFML/Graphics/Rect.hpp>


CollideComponent::CollideComponent(Entity& owner, const sf::Vector2f size)
	: Component(owner)
	, size(size)
{
}


CollideComponent::~CollideComponent()
{
}

component_type CollideComponent::GetType()
{
	return component_type::collide;
}

void CollideComponent::SetGroup(group component_group)
{
	group_id = component_group;
}

void CollideComponent::SetCollidingGroup(const std::vector<group>& colliding)
{
	colliding_groups = colliding;
}

const std::vector<CollideComponent::group>& CollideComponent::GetCollidingGroup()
{
	return colliding_groups;
}

const sf::FloatRect CollideComponent::GetCollideArea()
{
	return sf::FloatRect(owner->GetPositionComponent()->GetPosition(), size);
}

void CollideComponent::SetCallback(CollideComponent::callback function, EngineObject* object)
{
	callback_fn = function;
	callback_object = object;
}

void CollideComponent::CheckCollisions(std::shared_ptr<CollideComponent>& collider)
{
	if (!collider->HasOwner())
		return;

	auto main_collide = GetCollideArea();
	auto other_collide = collider->GetCollideArea();

	if (main_collide.intersects(other_collide))
	{
		callback_fn(callback_object, *this, collider);
	}
}
