#include "ScriptComponent.h"



ScriptComponent::ScriptComponent(Entity& owner)
	: Component(owner)
{
}


ScriptComponent::~ScriptComponent()
{
}

component_type ScriptComponent::GetType()
{
	return component_type::script;
}

void ScriptComponent::SetScript(callback function, EngineObject* object)
{
	callback_fn = function;
	callback_object = object;
}

void ScriptComponent::Execute(const sf::Time& delta_time)
{
	callback_fn(callback_object, delta_time);
}
