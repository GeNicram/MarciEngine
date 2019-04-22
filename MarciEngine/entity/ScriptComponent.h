#pragma once
#include "Component.h"

#include "Entity.h"

#include <SFML/System/Time.hpp>

#include <functional>

class ScriptComponent :
	public Component
{
public:
	typedef std::function<void(EngineObject* object, const sf::Time&)> callback;

	ScriptComponent(Entity& owner);
	~ScriptComponent();
	virtual component_type GetType() override;
	void SetScript(callback function, EngineObject* object);
	void Execute(const sf::Time& delta_time);

private:
	callback callback_fn;
	EngineObject* callback_object;
};

