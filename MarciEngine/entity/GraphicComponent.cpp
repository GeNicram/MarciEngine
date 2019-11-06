#include "GraphicComponent.h"

#include "Entity.h"
#include "PositionComponent.h"
#include "../resource/GraphicPrimitive.h"



GraphicComponent::GraphicComponent(Entity& owner, Graphic& graphic)
	: Component(owner)
	, graphic(graphic)
{
}

component_type GraphicComponent::GetType()
{
	return component_type::graphic;
}

GraphicComponent::~GraphicComponent()
{
	if (dynamic_cast<GraphicPrimitive*>(&graphic))
	{
		graphic.Remove();
	}
}

void GraphicComponent::Render(sf::RenderWindow& target)
{
	Entity valid_owner = owner.lock();
	std::vector<std::shared_ptr<Component>> positions = valid_owner->GetComponents(component_type::position);

	for (auto& position : positions)
	{
		auto pos = std::dynamic_pointer_cast<PositionComponent>(position)->GetPosition();
		sf::Transformable tr;
		tr.setPosition(pos);
		target.draw(graphic.GetDrawing(tr));
	}
}
