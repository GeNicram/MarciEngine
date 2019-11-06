#include "SummaryScene.h"

#include <cassert>


SummaryScene::SummaryScene()
{
	game_over = EntityBase::Create()
		.AddGraphic("Assets/summary.png", 100)
		.AddPosition(sf::Vector2f(400, 200))
		.AddControl({ sf::Keyboard::Space }, ToTitleCallback, this);
}


SummaryScene::~SummaryScene()
{
}

void SummaryScene::Update(sf::Time delta_time)
{

}

void SummaryScene::HandleCollision(EntityPtr collide, EntityPtr touched)
{

}

void SummaryScene::ToTitleCallback(EngineObject* object, const sf::Event& event)
{
	SummaryScene* scene = dynamic_cast<SummaryScene*>(object);
	assert(scene);
	if (!scene)
		return;

	scene->ToTitle(event);
}

void SummaryScene::ToTitle(const sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased)
		current_operation = to_title;
}
