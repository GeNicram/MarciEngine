#pragma once

#include "Scene.h"
#include <entity/Entity.h>
#include <EngineObject.h>

class TitleScene : public Scene
{
public:
	TitleScene();
	virtual ~TitleScene();

	virtual void Update(sf::Time delta_time) override;
	virtual void HandleCollision(Entity* collide, Entity* touched) override;

	static void ToGameplayCallback(EngineObject* object, const sf::Event& event);
	void ToGameplay(const sf::Event& event);
private:
	Entity welcome;
};

