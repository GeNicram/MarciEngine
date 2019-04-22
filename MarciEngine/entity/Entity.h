#pragma once

#include "../EngineObject.h"
#include "Component.h"
#include "PositionComponent.h"
#include "ComponentTypes.h"

#include <vector>
#include <memory>

class Component;
class GraphicComponent;
class PositionComponent;
class EntityBuilder;

class Entity : EngineObject
{
public:
	Entity();
	Entity(Entity& other);
	Entity(Entity&& other);
	Entity& operator=(Entity&& other);
	Entity& operator=(const Entity& other);

	~Entity();
	static EntityBuilder Create();

	void Activate();
	void Deactivate();
	bool IsActive();

	void AddComponent(std::shared_ptr<Component> component);

	std::vector<std::shared_ptr<Component>> GetComponents(component_type type);
	std::shared_ptr<PositionComponent> GetPositionComponent();

	friend class EntityBuilder;
private:
	bool active;
	std::vector<std::shared_ptr<Component>> components;
	bool abandon_components_after_delete;

	void UpdateComponentsOwner();
	void AbandonComponents();
};

