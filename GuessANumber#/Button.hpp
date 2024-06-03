#pragma once
#include <SFML/Graphics.hpp>
#include <string.h>

class Button
{
	public:
		Button(std::string filePath);
		void Render(sf::RenderWindow& window);
		void SetPosition(sf::Vector2f position);
		void SetScale(sf::Vector2f scale);
		sf::Sprite GetSprite();
		bool IsMouseOnButton(sf::RenderWindow& window);
		bool IsMouseOnButtonRect(sf::RenderWindow& window);
		void ScaleOnHover(sf::Vector2f scaleTo, sf::Vector2f scaleBackTo, sf::RenderWindow& window);
		void ScaleOnHover(sf::RectangleShape& rect, sf::Vector2f scaleTo, sf::Vector2f scaleBackTo, sf::RenderWindow& window);
		void SetText(std::string levelName, unsigned int characterSize);
		void SetRectangle(sf::Vector2f size, sf::Color outlineColor, float outlineThickness, sf::Vector2f position, sf::Color fillColor);

		sf::RectangleShape& GetRectangle();

	private:
		sf::Texture texture;
		sf::Sprite sprite;
		sf::Font font;
		sf::Text text;
		sf::RectangleShape rectangle;
};

