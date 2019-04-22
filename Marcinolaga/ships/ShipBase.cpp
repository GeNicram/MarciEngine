#include "ShipBase.h"

#include <entity/Entity.h>
#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

ShipBase::ShipBase()
{
}


ShipBase::~ShipBase()
{
}

const sf::Vector2f ShipBase::GetPosition()
{
	return entity.GetPositionComponent()->GetPosition();
}

void ShipBase::SetPosition(const sf::Vector2f& position)
{
	entity.GetPositionComponent()->SetPosition(position);
}

const Entity& ShipBase::GetEntity() const
{
	return entity;
}
