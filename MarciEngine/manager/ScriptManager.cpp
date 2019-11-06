#include "ScriptManager.h"

#include <algorithm>



ScriptManager::ScriptManager()
{
}


ScriptManager::~ScriptManager()
{
}

std::shared_ptr<ScriptComponent> ScriptManager::ApplyScript(Entity& entity, ScriptComponent::callback callback,
	EngineObject* object)
{
	std::vector<std::shared_ptr<ScriptComponent>>::iterator new_script =
		new_script_components.emplace(new_script_components.end(), new ScriptComponent(entity));

	entity->AddComponent(*new_script);

	(*new_script)->SetScript(callback, object);

	return *new_script;
}

void ScriptManager::Execute(const sf::Time& delta_time)
{
	for (auto script = script_components.begin(); script != script_components.end();)
	{
		if ((*script)->HasOwner())
		{
			(*script)->Execute(delta_time);
			++script;
		}
		else
		{
			script = script_components.erase(script);
		}
	}

	script_components.insert(script_components.end(), new_script_components.begin(), new_script_components.end());
	new_script_components.clear();
}
