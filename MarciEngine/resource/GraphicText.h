#pragma once
#include "Graphic.h"
class GraphicText :
	public Graphic
{
public:
	typedef std::size_t hash;
	GraphicText(const std::string& font_path, const std::string& text);
	~GraphicText();

	void StartLoad();

	void SetSize(const float size);
	void SetColor(const sf::Color& color);

	virtual const sf::Drawable& GetDrawing(const sf::Transformable& transform) override;
private:
	void SetFont(std::shared_ptr<sf::Font>& font);
	void SetReady();

	std::string font_path;
	hash hash_number;
	std::shared_ptr<sf::Font> font;
	sf::Text text;

	friend class GraphicManager;
};

