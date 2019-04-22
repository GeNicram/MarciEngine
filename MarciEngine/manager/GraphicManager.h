#pragma once

#include "../entity/GraphicComponent.h"
#include "../resource/Graphic.h"
#include "../resource/GraphicPrimitive.h"
#include "../resource/GraphicTexture.h"
#include "../resource/GraphicText.h"

#include <map>
#include <string>


class GraphicManager
{
public:
	GraphicManager();
	~GraphicManager();

	void SetTargetWindow(sf::RenderWindow* target);

	GraphicTexture& AddTextureGraphic(const std::string path);
	Graphic& AddPrimitiveGraphic(const GraphicPrimitive::type primitive_type);
	GraphicText& AddTextGraphic(const std::string& font_path, const std::string& text);

	std::shared_ptr<GraphicComponent> ApplyGraphic(Entity& entity, Graphic& graphic, GraphicComponent::layer layer);

	void Render();
	void ReleaseResources();
private:
	sf::RenderWindow* target_window;
	std::multimap<GraphicComponent::layer, std::shared_ptr<GraphicComponent>> graphic_components;

	std::map<GraphicTexture::hash, GraphicTexture> texture_resources;
	std::map<GraphicText::hash, std::shared_ptr<sf::Font>> font_resources;
	std::vector<std::unique_ptr<Graphic>> graphic_resources;
};

