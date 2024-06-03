#include "MyGame.hpp"

MyGame::MyGame() : startButton("..\\space-gui\\PNG\\Main_Menu\\Start_BTN.png"), 
                   exitButton("..\\space-gui\\PNG\\Main_Menu\\Exit_BTN.png"),
                   levelOneButton("..\\space-gui\\PNG\\Level_Menu\\Star_01.png"),
				   levelTwoButton("..\\space-gui\\PNG\\Level_Menu\\Star_02.png"),
				   levelThreeButton("..\\space-gui\\PNG\\Level_Menu\\Star_03.png")
{
    startButton.SetPosition(sf::Vector2f(window.getSize().x / 2, 200));
	exitButton.SetPosition(sf::Vector2f(window.getSize().x / 2, 350));

    levelOneButton.SetPosition(sf::Vector2f(100, 100));
    levelOneButton.SetScale(sf::Vector2f(0.3f, 0.3f));
    levelOneButton.SetRectangle(sf::Vector2f(700, 150), sf::Color::White, 2.0f, sf::Vector2f(window.getSize().x / 2, 100), sf::Color::Black);
    levelOneButton.SetText("Level 1", 50);

	levelTwoButton.SetPosition(sf::Vector2f(100, 300));
	levelTwoButton.SetScale(sf::Vector2f(0.3f, 0.3f));
	levelTwoButton.SetRectangle(sf::Vector2f(700, 150), sf::Color::White, 2.0f, sf::Vector2f(window.getSize().x / 2, 300), sf::Color::Black);
	levelTwoButton.SetText("Level 2", 50);

	levelThreeButton.SetPosition(sf::Vector2f(100, 500));
    levelThreeButton.SetScale(sf::Vector2f(0.3f, 0.3f));
	levelThreeButton.SetRectangle(sf::Vector2f(700, 150), sf::Color::White, 2.0f, sf::Vector2f(window.getSize().x / 2, 500), sf::Color::Black);
	levelThreeButton.SetText("Level 3", 50);

    inputText.SetPosition(sf::Vector2f(0, 0));
    inputText.SetcharacterSize(50);

    userText.SetPosition(sf::Vector2f(380, 0));
	userText.SetcharacterSize(50);

    srand(time(NULL));

	gameState = MyGame::StartMenu;
}

void MyGame::ProcessEvents() 
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }

        switch (gameState)
        {
            case MyGame::StartMenu:
            {
			    handleStartMenuEvents(event);
                break;
            }
            case MyGame::LevelSelection:
            {
                handleLevelSelectionEvents(event);
                break;
            }
            case MyGame::Playing:
            {
                handlePlayingEvents(event);
                break;
            }
			case MyGame::Win:
			{
                handleWinEvents(event);
				break;
			}
            case MyGame::GameOver:
            {

                break;
            }
            default:
                std::cerr << "Invalid game state" << std::endl;
                break;
        }
    }
}

void MyGame::Update(sf::Time deltaTime)
{
    // Update game logic

    switch (gameState)
    {
    case MyGame::StartMenu:
    {
        break;
    }
    case MyGame::LevelSelection:
    {
        break;
    }
    case MyGame::Playing:
    {
        std::cout << "Random number: " << rndNumber << std::endl;
        CheckNumber(userInput, rndNumber, userText, inputText);
        break;
    }
	case MyGame::Win:
	{
		WinText();
		break;
	}
    case MyGame::GameOver:
    {

        break;
    }
    default:
        std::cerr << "Invalid game state" << std::endl;
        break;
    }
}

void MyGame::Render()
{
    window.clear();

    switch (gameState)
    {
        case MyGame::StartMenu:
        {
            startButton.Render(window);
		    exitButton.Render(window);
            break;
        }
        case MyGame::LevelSelection:
        {
            levelOneButton.Render(window);
            levelTwoButton.Render(window);
            levelThreeButton.Render(window);

            break;
        }
        case MyGame::Playing:
        {
            inputText.Render(window);
			userText.Render(window);
            break;
        }
        case MyGame::Win:
		{
            hasWonText.Render(window);
            inputText.Render(window);
			userText.Render(window);
			break;
		}
        case MyGame::GameOver:
        {

            break;
        }
        default:
            std::cerr << "Invalid game state in draw" << std::endl;
            break;
    }

    window.display();
}


void MyGame::handleStartMenuEvents(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (startButton.IsMouseOnButton(window))
        {
            gameState = MyGame::LevelSelection;
        }

        if (exitButton.IsMouseOnButton(window))
        {
            window.close();
        }
    }

    startButton.ScaleOnHover(sf::Vector2f(1.1f, 1.1f), sf::Vector2f(1.0f, 1.0f), window);
    exitButton.ScaleOnHover(sf::Vector2f(1.1f, 1.1f), sf::Vector2f(1.0f, 1.0f), window);
}

void MyGame::handleLevelSelectionEvents(sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        if (levelOneButton.IsMouseOnButtonRect(window))
        {
			rndNumber = rand() % 10 + 1;
            gameState = MyGame::Playing;
        }

        if (levelTwoButton.IsMouseOnButtonRect(window))
        {
			rndNumber = rand() % 50 + 1;
            gameState = MyGame::Playing;
        }

        if (levelThreeButton.IsMouseOnButtonRect(window))
        {
            rndNumber = rand() % 100 + 1;
            gameState = MyGame::Playing;
        }
    }

    levelOneButton.ScaleOnHover(levelOneButton.GetRectangle(), sf::Vector2f(1.1f, 1.1f), sf::Vector2f(1.0f, 1.0f), window);
    levelTwoButton.ScaleOnHover(levelTwoButton.GetRectangle(), sf::Vector2f(1.1f, 1.1f), sf::Vector2f(1.0f, 1.0f), window);
    levelThreeButton.ScaleOnHover(levelThreeButton.GetRectangle(), sf::Vector2f(1.1f, 1.1f), sf::Vector2f(1.0f, 1.0f), window);
}

void MyGame::handlePlayingEvents(sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}

    inputText.SetText("Please enter a number: ");

    if (event.type == sf::Event::TextEntered)
    {
        userInputText += event.text.unicode;

        for (size_t i = 0; i < userInputText.size(); i++)
        {
            if (userInputText[i] == '\r' || userInputText[i] == '\b')
            {
                userInputText.erase(i, 1);
            }
        }

        userText.SetText(userInputText);
    }

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.scancode == sf::Keyboard::Scan::Enter)
        {
            try
            {
                userInput = std::stoi(userInputText);
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << e.what() << std::endl;
            }
            catch (const std::out_of_range& e)
            {
                std::cout << e.what() << std::endl;
            }

            userInputText.clear();
        }

        if (event.key.scancode == sf::Keyboard::Scan::Backspace)
        {
            if (userInputText.size() > 0)
            {
                userInputText.pop_back();
                userText.SetText(userInputText);
            }
            else
            {
                //break;
            }
        }
    }
}

void MyGame::handleWinEvents(sf::Event& event)
{
	if (event.type == sf::Event::Closed)
	{
		window.close();
	}

    inputText.SetText("Want to play again? Yes or No");
    userText.SetPosition(sf::Vector2f(0, 50));

    if (event.type == sf::Event::TextEntered)
    {
        //userText.setPosition(400, 0);
        userInputText += event.text.unicode;

        for (size_t i = 0; i < userInputText.size(); i++)
        {
            if (userInputText[i] == '\r' || userInputText[i] == '\b')
            {
                userInputText.erase(i, 1);
            }
        }

        userText.SetText(userInputText);
    }

    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.scancode == sf::Keyboard::Scan::Enter)
        {
            userInputText = userInputText;

            if (userInputText == "yes" || userInputText == "y")
            {
                // Play again -> to level choose menu
                gameState = MyGame::LevelSelection;
            }
            else if (userInputText == "no" || userInputText == "n")
            {
                // Dont want to play again -> back to main menu
                gameState = MyGame::StartMenu;
            }
            userText.SetPosition(sf::Vector2f(380, 0));
            userInputText.clear();
            userText.SetText("");
        }

        if (event.key.scancode == sf::Keyboard::Scan::Backspace)
        {
            if (userInputText.size() > 0)
            {
                userInputText.pop_back();
                userText.SetText(userInputText);
            }
            else
            {
                //break;
            }
        }
    }
}

void MyGame::CheckNumber(int& userInput, int& rndNumber, Text& userText, Text& inputText)
{
    if (userInput != 0)
    {
        if (userInput > rndNumber)
        {
            inputText.SetText("Please enter a lower number: ");
            userText.SetPosition(sf::Vector2f(450, 0));
        }
        else if (userInput < rndNumber)
        {
            inputText.SetText("Please enter a higher number: ");
            userText.SetPosition(sf::Vector2f(460, 0));
        }
        else if (userInput == rndNumber)
        {
            userText.SetPosition(sf::Vector2f(380, 0));
            userInput = 0;
            gameState = MyGame::Win;
        }
    }
}

void MyGame::WinText()
{
    hasWonText.SetText("You won!");
    hasWonText.SetPosition(sf::Vector2f(0, 150));
    hasWonText.SetcharacterSize(50);
}
