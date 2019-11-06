#pragma once

#include <EngineObject.h>
#include <MarciEngine.h>
#include <entity/EntityBuilder.h>
#include <entity/ControlComponent.h>
#include <SFML/Graphics.hpp>

class Bullet;

class Scene : public EngineObject
{
public:
	enum operation { working, to_title, to_gameplay, to_summary };
	Scene();
	virtual ~Scene();

	static void UpdateCallback(EngineObject* object, sf::Time delta_time);
	virtual void Update(sf::Time delta_time) = 0;

	operation GetOperation();

	virtual void HandleCollision(EntityPtr collide, EntityPtr touched) = 0;
protected:
	operation current_operation;
};

