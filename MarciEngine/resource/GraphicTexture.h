#pragma once
#include "Graphic.h"
class GraphicTexture :
	public Graphic
{
public:
	typedef std::size_t hash;

	GraphicTexture(const std::string path);
	GraphicTexture(const std::string path, hash hash);
	~GraphicTexture();
	void StartLoad();
	hash GetHash();
	virtual const sf::Drawable& GetDrawing(const sf::Transformable& transform) override;

private:
	void SetReady();
	std::string path;
	hash hash_number;
	std::unique_ptr<sf::Texture> texture;
	sf::Sprite sprite;
};

