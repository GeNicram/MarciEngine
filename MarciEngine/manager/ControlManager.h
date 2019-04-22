#pragma once

#include "../entity/ControlComponent.h"

#include <SFML/Window.hpp>

#include <functional>
#include <vector>
#include <map>

class ControlManager
{
public:
	ControlManager();
	~ControlManager();
	void HandleEvents(sf::Window& event_source);
	std::vector<std::shared_ptr<ControlComponent>> ApplyControl(Entity& entity,
		const std::vector<sf::Keyboard::Key>& keys, ControlComponent::callback function,
		EngineObject* object);

	void ReleaseBindings();
private:
	std::multimap<sf::Keyboard::Key, std::shared_ptr<ControlComponent>> control_components;
};

