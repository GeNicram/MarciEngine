#include "GraphicText.h"



GraphicText::GraphicText(const std::string& font_path, const std::string& text)
	: font_path(font_path)
{
	std::hash<std::string> hash_fn;
	hash_number = hash_fn(font_path);

	this->text.setString(text);

	current_status = created;
}


GraphicText::~GraphicText()
{
}

void GraphicText::StartLoad()
{
	if (current_status == ready || current_status == loading)
		return;

	// TODO: add verification if font is already loaded

	current_status = loading;
	if (font->loadFromFile(font_path))
	{
		SetReady();
	}
	else
		current_status = cant_load;
}

void GraphicText::SetSize(const float size)
{
	text.setCharacterSize(size);
}

void GraphicText::SetColor(const sf::Color& color)
{
	text.setFillColor(color);
}

void GraphicText::SetFont(std::shared_ptr<sf::Font>& font)
{
	this->font = font;
}

const sf::Drawable& GraphicText::GetDrawing(const sf::Transformable& transform)
{
	text.setPosition(transform.getPosition());
	text.setRotation(transform.getRotation());
	text.setScale(transform.getScale());

	return text;
}

void GraphicText::SetReady()
{
	current_status = ready;
	text.setFont(*font);
}