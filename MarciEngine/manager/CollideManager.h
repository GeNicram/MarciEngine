#pragma once

#include "../entity/CollideComponent.h"

#include <map>
#include <memory>

class CollideManager
{
public:
	CollideManager();
	~CollideManager();

	std::shared_ptr<CollideComponent> ApplyCollider(Entity& entity, CollideComponent::group group_id,
		const sf::Vector2f& collider_size, const std::vector<CollideComponent::group> collide_with);

	void HandleCollisions();
	void SingleGroupCollision(std::shared_ptr<CollideComponent> collide, const CollideComponent::group& group);

private:
	std::multimap<CollideComponent::group, std::shared_ptr<CollideComponent>> collide_components;
};

