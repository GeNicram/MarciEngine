#pragma once

#include "Entity.h"
#include "CollideComponent.h"
#include "ControlComponent.h"
#include "GraphicComponent.h"
#include "ScriptComponent.h"

#include <memory>

class EntityBuilderBase
{
protected:
	explicit EntityBuilderBase(Entity& entity);
public:
	~EntityBuilderBase();

	operator Entity() const;
	std::unique_ptr<Entity> Clone();

	EntityBuilderBase& AddCollide(CollideComponent::group group_id,
		const sf::Vector2f& collider_size, const std::vector<CollideComponent::group> collide_with,
		CollideComponent::callback function, EngineObject* object);
	EntityBuilderBase& AddControl(const std::vector<sf::Keyboard::Key>& keys, ControlComponent::callback function,
		EngineObject* object);
	EntityBuilderBase& AddGraphic(const std::string& path, GraphicComponent::layer layer);
	EntityBuilderBase& AddCircle(const float r, const sf::Color color, GraphicComponent::layer layer);
	EntityBuilderBase& AddRectangle(const float width, const float height,
		const sf::Color color, GraphicComponent::layer layer);
	EntityBuilderBase& AddText(const std::string& font_path, const std::string& text, GraphicComponent::layer layer);
	EntityBuilderBase& AddPosition(const sf::Vector2f& position);
	EntityBuilderBase& AddScript(ScriptComponent::callback function, EngineObject* object);
	EntityBuilderBase& AddSpawn();

private:
	Entity& entity;
};

class EntityBuilder : public EntityBuilderBase
{
	std::shared_ptr<Entity> entity;
public:
	EntityBuilder();
};

