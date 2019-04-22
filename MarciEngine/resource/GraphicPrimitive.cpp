#include "GraphicPrimitive.h"

GraphicPrimitive::GraphicPrimitive(type shape_type)
{
	switch (shape_type)
	{
	case type::circle:
		shape.reset(new sf::CircleShape());
		break;
	case type::rectangle:
		shape.reset(new sf::RectangleShape());
		break;
	}
}

GraphicPrimitive::~GraphicPrimitive()
{
	int a = 0;
}

void GraphicPrimitive::SetRadius(float r)
{
	sf::CircleShape& circle = dynamic_cast<sf::CircleShape&>(*shape);

	circle.setRadius(r);
	circle.setPointCount(4 + r / 2);
}

void GraphicPrimitive::SetSize(const float width, const float height)
{
	sf::RectangleShape& rectanble = dynamic_cast<sf::RectangleShape&>(*shape);

	rectanble.setSize(sf::Vector2f(width, height));
}

void GraphicPrimitive::SetColor(const sf::Color& color)
{
	shape->setFillColor(color);
}

const sf::Drawable& GraphicPrimitive::GetDrawing(const sf::Transformable& transforms)
{
	shape->setPosition(transforms.getPosition());
	shape->setRotation(transforms.getRotation());
	shape->setScale(transforms.getScale());

	return *shape;
}
