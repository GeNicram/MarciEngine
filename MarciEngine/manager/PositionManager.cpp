#include "PositionManager.h"

#include "../entity/Entity.h"
#include "../entity/PositionComponent.h"

#include <memory>
#include <vector>

// TODO
// Position manager has no update function and it newer free position_components

PositionManager::PositionManager()
{
}


PositionManager::~PositionManager()
{
}

std::shared_ptr<PositionComponent> PositionManager::ApplyPosition(Entity& entity, sf::Vector2f position)
{
	std::vector<std::shared_ptr<PositionComponent>>::iterator new_position =
		position_components.emplace(position_components.end(), new PositionComponent(entity));

	entity->AddComponent(*new_position);

	(*new_position)->SetPosition(position);

	return *new_position;
}

void PositionManager::Update()
{
	for (auto position = position_components.begin(); position != position_components.end();)
	{
		if (!(*position)->HasOwner())
		{
			position = position_components.erase(position);
		}
		else
		{
			++position;
		}
	}
}
