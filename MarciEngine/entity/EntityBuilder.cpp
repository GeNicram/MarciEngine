#include "EntityBuilder.h"

#include "ControlComponent.h"
#include "GraphicComponent.h"
#include "../manager/Managers.h"

#include "../resource/GraphicTexture.h"
#include "../resource/GraphicText.h"
#include "../resource/GraphicPrimitive.h"

#include <SFML/Window/Keyboard.hpp>

#include <cassert>


EntityBuilderBase::EntityBuilderBase(std::unique_ptr<EntityBase> entity)
	: entity(entity.release())
{
}


EntityBuilderBase::~EntityBuilderBase()
{
}

EntityBuilderBase::operator Entity()
{
	std::shared_ptr a = std::move(entity.release());
	return entity.release();
}

std::unique_ptr<Entity> EntityBuilderBase::Clone()
{
	assert(!"Not implemented");
	return nullptr;// std::copy(entity);
}

EntityBuilderBase& EntityBuilderBase::AddCollide(CollideComponent::group group_id,
	const sf::Vector2f& collider_size, const std::vector<CollideComponent::group> collide_with,
	CollideComponent::callback function, EngineObject* object)
{
	Managers::Get().collide_manager.ApplyCollider(entity, group_id, collider_size, collide_with)->
		SetCallback(function, object);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddControl(const std::vector<sf::Keyboard::Key>& keys,
	ControlComponent::callback function, EngineObject* object)
{
	Managers::Get().control_manager.ApplyControl(entity, keys, function, object);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddGraphic(const std::string& path, GraphicComponent::layer layer)
{
	GraphicTexture& g = Managers::Get().graphic_manager.AddTextureGraphic(path);
	g.StartLoad();
	Managers::Get().graphic_manager.ApplyGraphic(entity, g, layer);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddCircle(const float r, const sf::Color color, GraphicComponent::layer layer)
{
	Graphic& g = Managers::Get().graphic_manager.AddPrimitiveGraphic(GraphicPrimitive::circle);
	Managers::Get().graphic_manager.ApplyGraphic(entity, g, layer);

	GraphicPrimitive& gp = dynamic_cast<GraphicPrimitive&>(g);
	gp.SetRadius(r);
	gp.SetColor(color);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddRectangle(const float width, const float height,
	const sf::Color color, GraphicComponent::layer layer)
{
	Graphic& g = Managers::Get().graphic_manager.AddPrimitiveGraphic(GraphicPrimitive::rectangle);
	Managers::Get().graphic_manager.ApplyGraphic(entity, g, layer);

	GraphicPrimitive& gp = dynamic_cast<GraphicPrimitive&>(g);
	gp.SetSize(width, height);
	gp.SetColor(color);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddText(const std::string& font_path, const std::string& text,
	GraphicComponent::layer layer)
{
	GraphicText& gt = Managers::Get().graphic_manager.AddTextGraphic(font_path, text);
	gt.StartLoad();
	gt.SetColor(sf::Color::White);
	gt.SetSize(20.0f);
	Managers::Get().graphic_manager.ApplyGraphic(entity, gt, layer);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddPosition(const sf::Vector2f& position)
{
	Managers::Get().position_manager.ApplyPosition(entity, position);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddScript(ScriptComponent::callback function, EngineObject* object)
{
	Managers::Get().script_manager.ApplyScript(entity, function, object);

	return *this;
}

EntityBuilderBase& EntityBuilderBase::AddSpawn()
{

	return *this;
}

EntityBuilder::EntityBuilder()
	: EntityBuilderBase(entity)
{
}
