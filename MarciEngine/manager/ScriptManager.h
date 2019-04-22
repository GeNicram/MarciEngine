#pragma once

#include "../entity/ScriptComponent.h"

#include <memory>
#include <vector>

class ScriptManager
{
public:
	ScriptManager();
	~ScriptManager();
	std::shared_ptr<ScriptComponent> ApplyScript(Entity& entity, ScriptComponent::callback callback,
		EngineObject* object);
	void Execute(const sf::Time& deltatime);
private:
	std::vector<std::shared_ptr<ScriptComponent>> script_components;
	std::vector<std::shared_ptr<ScriptComponent>> new_script_components;
};

