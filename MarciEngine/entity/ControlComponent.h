#pragma once

#include "Component.h"
#include "../EngineObject.h"

#include <SFML/Window/Event.hpp>

#include <functional>
#include <memory>

class ControlComponent : public Component
{
public:
	typedef std::function<void(EngineObject* object, const sf::Event&)> callback;

	ControlComponent(Entity& owner);
	~ControlComponent();
	virtual component_type GetType() override;

	void SetCallback(callback function, EngineObject* object);
	void Execute(const sf::Event& event);

private:
	callback callback_fn;
	EngineObject* callback_object;
};

