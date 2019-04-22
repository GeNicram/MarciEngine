#include "ControlComponent.h"

#include "Entity.h"

ControlComponent::ControlComponent(Entity& owner)
	: Component(owner)
	, callback_object(nullptr)
{
}


ControlComponent::~ControlComponent()
{
}

component_type ControlComponent::GetType()
{
	return component_type::control;
}

void ControlComponent::SetCallback(callback function, EngineObject* object)
{
	callback_fn = function;
	callback_object = object;
}

void ControlComponent::Execute(const sf::Event& event)
{
	callback_fn(callback_object, event);
}
