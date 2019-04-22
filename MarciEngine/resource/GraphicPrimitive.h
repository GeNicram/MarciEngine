#pragma once
#include "Graphic.h"
class GraphicPrimitive :
	public Graphic
{
public:
	enum type { circle, rectangle };
	GraphicPrimitive(type shape_type);
	~GraphicPrimitive();

	void SetRadius(const float r);
	void SetSize(const float width, const float height);
	void SetColor(const sf::Color& color);

	virtual const sf::Drawable& GetDrawing(const sf::Transformable& transform) override;
private:
	std::unique_ptr<sf::Shape> shape;
};

