#pragma once
#include <SFML/Graphics.hpp>

class Text
{
	public:
		Text();
		void SetText(std::string text);
		void SetPosition(sf::Vector2f position);
		void SetcharacterSize(int characterSize);
		void Render(sf::RenderWindow& window);

	private:
		sf::Font font;
		sf::Text text;
};

