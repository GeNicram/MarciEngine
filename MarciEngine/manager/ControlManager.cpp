#include "ControlManager.h"

#include "../entity/Entity.h"

#include <SFML/Window.hpp>

ControlManager::ControlManager()
{
}


ControlManager::~ControlManager()
{
}

void ControlManager::HandleEvents(sf::Window& event_source)
{
	sf::Event event;
	while (event_source.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			event_source.close();

		if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
		{
			auto bind_components = control_components.equal_range(event.key.code);
			for (auto bind = bind_components.first; bind != bind_components.second;)
			{
				if (!bind->second->HasOwner())
				{
					bind = control_components.erase(bind);
				}
				else
				{
					bind->second->Execute(event);
					++bind;
				}
			}
		}
	}
}

std::vector<std::shared_ptr<ControlComponent>> ControlManager::ApplyControl(Entity& entity,
	const std::vector<sf::Keyboard::Key>& keys, ControlComponent::callback function, EngineObject* object)
{
	std::vector<std::shared_ptr<ControlComponent>> new_components;

	for (auto key : keys)
	{
		std::multimap<sf::Keyboard::Key, std::shared_ptr<ControlComponent>>::iterator new_control =
			control_components.emplace(key, new ControlComponent(entity));

		new_control->second->SetCallback(function, object);
		entity->AddComponent(new_control->second);

		new_components.push_back(new_control->second);
	}

	return new_components;
}

void ControlManager::ReleaseBindings()
{
	for (auto bind = control_components.begin(); bind != control_components.end();)
	{
		if (!bind->second->HasOwner())
		{
			bind = control_components.erase(bind);
		}
		else
			++bind;
	}
}
