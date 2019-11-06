#pragma once

#include "Scene.h"
#include <entity/Entity.h>
#include <EngineObject.h>

class SummaryScene : public Scene
{
public:
	SummaryScene();
	virtual ~SummaryScene();

	virtual void Update(sf::Time delta_time) override;
	virtual void HandleCollision(EntityPtr collide, EntityPtr touched) override;

	static void ToTitleCallback(EngineObject* object, const sf::Event& event);
	void ToTitle(const sf::Event& event);
private:
	Entity game_over;
};
