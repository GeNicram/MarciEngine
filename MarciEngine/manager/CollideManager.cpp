#include "CollideManager.h"



CollideManager::CollideManager()
{
}


CollideManager::~CollideManager()
{
}

std::shared_ptr<CollideComponent> CollideManager::ApplyCollider(EntityPtr entity, CollideComponent::group group_id,
	const sf::Vector2f& collider_size, const std::vector<CollideComponent::group> collide_with)
{

	auto new_component = collide_components.emplace(group_id, new CollideComponent(entity, collider_size));

	auto component = new_component->second;

	component->SetGroup(group_id);
	component->SetCollidingGroup(collide_with);
	entity.AddComponent(component);

	return new_component->second;
}

void CollideManager::HandleCollisions()
{
	for (auto collide = collide_components.begin(); collide != collide_components.end();)
	{
		if (collide->second->HasOwner())
		{
			auto group = collide->second->GetCollidingGroup();

			std::for_each(group.begin(), group.end(),
				[&](const CollideComponent::group& group_id)
			{
				SingleGroupCollision(collide->second, group_id);
			});

			++collide;
		}
		else
			collide = collide_components.erase(collide);
	}
}

void CollideManager::SingleGroupCollision(std::shared_ptr<CollideComponent> collide,
	const CollideComponent::group& group)
{
	auto colliders_in_group = collide_components.equal_range(group);

	for (auto collider_in_group = colliders_in_group.first; collider_in_group != colliders_in_group.second;
		++collider_in_group)
	{
		if (!collide->HasOwner())
			break;

		collide->CheckCollisions(collider_in_group->second);
	};
}
