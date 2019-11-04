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
	EntityBase(EntityBase& other);
	EntityBase(EntityBase&& other);
	EntityBase& operator=(EntityBase&& other);
	EntityBase& operator=(const EntityBase& other);

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
