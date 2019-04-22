#pragma once

#include "../entity/Entity.h"
#include "../entity/PositionComponent.h"

#include <SFML/System/Vector2.hpp>

#include <memory>
#include <vector>

class PositionManager
{
public:
	PositionManager();
	~PositionManager();
	std::shared_ptr<PositionComponent> ApplyPosition(Entity& entity, sf::Vector2f position);
	void Update();
private:
	std::vector<std::shared_ptr<PositionComponent>> position_components;
};

