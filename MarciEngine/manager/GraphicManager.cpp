#include "GraphicManager.h"

#include "../entity/Entity.h"

#include "../resource/GraphicTexture.h"
#include "../resource/GraphicText.h"
#include "../resource/GraphicPrimitive.h"

#include <cassert>
#include <functional>

GraphicManager::GraphicManager()
	: target_window(nullptr)
{
}


GraphicManager::~GraphicManager()
{
	graphic_components.clear();
}

void GraphicManager::SetTargetWindow(sf::RenderWindow* target)
{
	target_window = target;
}

GraphicTexture& GraphicManager::AddTextureGraphic(const std::string path)
{
	static const std::hash<std::string> hash_fn;
	GraphicTexture::hash hash = hash_fn(path);

	std::map<GraphicTexture::hash, GraphicTexture>::iterator new_graphic = texture_resources.find(hash);
	if (new_graphic == texture_resources.end())
		new_graphic = texture_resources.emplace(hash, path).first;

	return new_graphic->second;
}

Graphic& GraphicManager::AddPrimitiveGraphic(const GraphicPrimitive::type primitive_type)
{
	auto new_graphic = graphic_resources.emplace(graphic_resources.end(), new GraphicPrimitive(primitive_type));

	return **new_graphic;
}

GraphicText& GraphicManager::AddTextGraphic(const std::string& font_path, const std::string& text)
{
	static const std::hash<std::string> hash_fn;
	GraphicText::hash hash = hash_fn(font_path);

	auto new_font = font_resources.find(hash);
	if (new_font == font_resources.end())
		new_font = font_resources.emplace(hash, new sf::Font()).first;

	auto new_graphic = graphic_resources.emplace(graphic_resources.end(), new GraphicText(font_path, text));
	GraphicText& new_text = dynamic_cast<GraphicText&>(**new_graphic);

	new_text.SetFont(new_font->second);

	return new_text;
}

std::shared_ptr<GraphicComponent> GraphicManager::ApplyGraphic(
	Entity& entity, Graphic& graphic, GraphicComponent::layer layer)
{
	std::map<GraphicComponent::layer, std::shared_ptr<GraphicComponent>>::iterator new_component =
		graphic_components.emplace(layer, new GraphicComponent(entity, graphic));

	auto component = new_component->second;

	component->layer_id = layer;
	entity->AddComponent(component);

	return new_component->second;
}

void GraphicManager::Render()
{
	assert(target_window != nullptr);
	if (!target_window)
		return;
	
	for (auto graphic = graphic_components.begin(); graphic != graphic_components.end();)
	{
		if (!graphic->second->HasOwner())
		{
			graphic = graphic_components.erase(graphic);
		}
		else
		{
			graphic->second->Render(*target_window);
			++graphic;
		}
	}
}

void GraphicManager::ReleaseResources()
{
	for (auto res = graphic_resources.begin(); res != graphic_resources.end();)
	{
		if ((*res)->GetStatus() == Graphic::remove)
		{
			res = graphic_resources.erase(res);
		}
		else
			++res;
	}
}
