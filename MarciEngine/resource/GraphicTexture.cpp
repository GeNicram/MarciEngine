#include "GraphicTexture.h"

GraphicTexture::GraphicTexture(const std::string path)
	: path(path)
{
	std::hash<std::string> hash_fn;
	hash_number = hash_fn(path);

	current_status = created;
}

GraphicTexture::GraphicTexture(const std::string path, hash hash_number)
	: path(path)
	, hash_number(hash_number)
{
}

GraphicTexture::~GraphicTexture()
{
}

void GraphicTexture::StartLoad()
{
	if (current_status == ready || current_status == loading)
		return;

	current_status = loading;

	texture.reset(new sf::Texture());

	if (texture->loadFromFile(path))
	{
		SetReady();
	}
	else
		current_status = cant_load;
}

void GraphicTexture::SetReady()
{
	current_status = ready;
	sprite.setTexture(*texture);
}

GraphicTexture::hash GraphicTexture::GetHash()
{
	return hash_number;
}

const sf::Drawable& GraphicTexture::GetDrawing(const sf::Transformable& transforms)
{
	sprite.setPosition(transforms.getPosition());
	sprite.setRotation(transforms.getRotation());
	sprite.setScale(transforms.getScale());

	return sprite;
}
