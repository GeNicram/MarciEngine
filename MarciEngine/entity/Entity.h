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

class EntityBase : EngineObject
{
public:
	EntityBase();
	EntityBase(Entity& other);
	EntityBase(Entity&& other);
	Entity& operator=(Entity&& other);
	Entity& operator=(const Entity& other);

	~EntityBase();
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

class Entity : public std::shared_ptr<EntityBase>
{

};
