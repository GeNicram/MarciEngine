#pragma once
#include "Component.h"
#include "Entity.h"

#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include <functional>
#include <memory>

class CollideComponent : public Component
{
public:
	typedef int group;
	typedef std::function<void(EngineObject* object,
		CollideComponent& collide,
		std::shared_ptr<CollideComponent>& touched)> callback;

	CollideComponent(Entity& owner, const sf::Vector2f size);
	~CollideComponent();

	virtual component_type GetType() override;
	void SetGroup(group component_group);
	void SetCollidingGroup(const std::vector<group>& colligind);
	const std::vector<group>& GetCollidingGroup();
	const sf::FloatRect& GetCollideArea();

	void SetCallback(callback function, EngineObject* object);
	void CheckCollisions(std::shared_ptr<CollideComponent>& collider);

private:
	sf::Vector2f size;
	group group_id;
	std::vector<group> colliding_groups;

	callback callback_fn;
	EngineObject* callback_object;
};

