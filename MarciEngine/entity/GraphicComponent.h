#pragma once
#include "Component.h"

#include "../resource/Graphic.h"

#include <SFML/Graphics.hpp>

class GraphicComponent :
	public Component
{
public:
	~GraphicComponent();
	virtual component_type GetType() override;
	void Render(sf::RenderWindow& target);

	typedef int layer;
private:
	GraphicComponent(Entity& owner, Graphic& graphic);
	layer layer_id;
	Graphic& graphic;

	friend class GraphicManager;
};

