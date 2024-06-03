#include "Text.hpp"

Text::Text()
{
	font.loadFromFile("GreatVibes-Regular.ttf");
	text.setFont(font);
}

void Text::SetText(std::string outputText)
{
	text.setString(outputText);
}

void Text::SetPosition(sf::Vector2f position)
{
	text.setPosition(position);
}

void Text::SetcharacterSize(int characterSize)
{
	text.setCharacterSize(characterSize);
}

void Text::Render(sf::RenderWindow& window)
{
	window.draw(text);
}
