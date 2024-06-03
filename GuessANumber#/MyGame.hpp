#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "Button.hpp"
#include "Text.hpp"
#include <iostream>

class MyGame : public Game 
{
    public:
        MyGame();
        enum GameState { StartMenu, LevelSelection, Playing, Win, GameOver };

    protected:
        void handleStartMenuEvents(sf::Event& event);
        void handleLevelSelectionEvents(sf::Event& event);
        void handlePlayingEvents(sf::Event& event);

        void handleWinEvents(sf::Event& event);

        void CheckNumber(int& userInput, int& rndNumber, Text& userText, Text& inputText);

        void WinText();

        void ProcessEvents() override;
        void Update(sf::Time deltaTime) override;
        void Render() override;

    private:
	    GameState gameState;

        Button startButton;
        Button exitButton;
        Button levelOneButton;
	    Button levelTwoButton;
	    Button levelThreeButton;

        Text inputText;
        Text userText;
	    Text hasWonText;

        std::string userInputText;

        int userInput = 0;
        int rndNumber = 0;
};
