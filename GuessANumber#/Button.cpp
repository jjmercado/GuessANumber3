#include "Button.hpp"
Button::Button(std::string filePath) : rectangle(sf::Vector2f(0,0))
{
	font.loadFromFile("GreatVibes-Regular.ttf");
	texture.loadFromFile(filePath);
	sprite.setTexture(texture);
	sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
}

void Button::Render(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(sprite);
	window.draw(text);
}

void Button::SetScale(sf::Vector2f scale)
{
	sprite.setScale(scale);
}

sf::Sprite Button::GetSprite()
{
	return sprite;
}

void Button::SetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

bool Button::IsMouseOnButton(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > sprite.getPosition().x - sprite.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).x < sprite.getPosition().x + sprite.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).y > sprite.getPosition().y - sprite.getLocalBounds().height / 2 &&
		sf::Mouse::getPosition(window).y < sprite.getPosition().y + sprite.getLocalBounds().height / 2)
	{
		return true;
	}
	return false;
}

bool Button::IsMouseOnButtonRect(sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > rectangle.getPosition().x - rectangle.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).x < rectangle.getPosition().x + rectangle.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).y > rectangle.getPosition().y - rectangle.getLocalBounds().height / 2 &&
		sf::Mouse::getPosition(window).y < rectangle.getPosition().y + rectangle.getLocalBounds().height / 2)
	{
		return true;
	}
	return false;
}

void Button::ScaleOnHover(sf::RectangleShape& rect, sf::Vector2f scaleTo, sf::Vector2f scaleBackTo, sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > rect.getPosition().x - rect.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).x < rect.getPosition().x + rect.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).y > rect.getPosition().y - rect.getLocalBounds().height / 2 &&
		sf::Mouse::getPosition(window).y < rect.getPosition().y + rect.getLocalBounds().height / 2)
	{
		rect.setScale(scaleTo);
	}
	else
	{
		rect.setScale(scaleBackTo);
	}
}

void Button::ScaleOnHover(sf::Vector2f scaleTo, sf::Vector2f scaleBackTo, sf::RenderWindow& window)
{
	if (sf::Mouse::getPosition(window).x > sprite.getPosition().x - sprite.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).x < sprite.getPosition().x + sprite.getLocalBounds().width / 2 &&
		sf::Mouse::getPosition(window).y > sprite.getPosition().y - sprite.getLocalBounds().height / 2 &&
		sf::Mouse::getPosition(window).y < sprite.getPosition().y + sprite.getLocalBounds().height / 2)
	{
		sprite.setScale(scaleTo);
	}
	else
	{
		sprite.setScale(scaleBackTo);
	}
}

void Button::SetText(std::string levelName, unsigned int characterSize)
{
	text.setFont(font);
	text.setPosition(sf::Vector2f(rectangle.getPosition().x - 50, rectangle.getPosition().y - 30));
	text.setString(levelName);
	text.setCharacterSize(characterSize);
}

void Button::SetRectangle(sf::Vector2f size, sf::Color outlineColor, float outlineThickness, sf::Vector2f position, sf::Color fillColor)
{
	rectangle.setSize(size);
	rectangle.setOutlineColor(outlineColor);
	rectangle.setOutlineThickness(outlineThickness);
	rectangle.setPosition(position);
	rectangle.setOrigin(rectangle.getSize().x / 2, rectangle.getSize().y / 2);
	rectangle.setFillColor(fillColor);
}

sf::RectangleShape& Button::GetRectangle()
{
	return rectangle;
}