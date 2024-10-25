// Main
// Entry point of the application.
// Handles window creation and window events.
// Contains the game loop, updates input class and contains the level objects.
// @author Paul Robertson

#include <iostream>
#include "Level.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include"MainMenu.h"
#include"Controls.h"
#include"Final.h"
#include"End.h"

void windowProcess(sf::RenderWindow* window, Input* in)
{
	// Handle window events.
	sf::Event event;
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::Resized:
			window->setView(sf::View(sf::FloatRect(0.f, 0.f, (float)event.size.width, (float)event.size.height)));
			break;
		case sf::Event::KeyPressed:
			// update input class
			in->setKeyDown(event.key.code);
			break;
		case sf::Event::KeyReleased:
			//update input class
			in->setKeyUp(event.key.code);
			break;
		case sf::Event::MouseMoved:
			//update input class
			in->setMousePosition(event.mouseMove.x, event.mouseMove.y);
			break;
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::DOWN);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::DOWN);
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				//update input class
				in->setLeftMouse(Input::MouseState::UP);
			}
			else if (event.mouseButton.button == sf::Mouse::Right)
			{
				in->setRightMouse(Input::MouseState::UP);
			}
			break;
		default:
			// don't handle other events
			break;
		}
	}
}

int main()
{
	//Create the window
	sf::RenderWindow window(sf::VideoMode(1200, 675), "TopDownShooter");

	// Initialise input and level objects.
	AudioManager audioManager;
	Input input;
	GameState gameState;
	Level level(&window, &input, &gameState, &audioManager);	  //
	MainMenu mainmenu(&window, &input, &gameState);				  //
	Controls controls(&window, &input, &gameState);				  //
	Final final(&window, &input, &gameState);						  //
	End end(&window, &input, &gameState);							  //
																  //
	// Initialise objects for delta time
	sf::Clock clock;
	float deltaTime;

	// Game Loop
	gameState.setCurrentState(State::MAINMENU);

	while (window.isOpen())
	{
		//Process window events
		windowProcess(&window, &input);

		// Calculate delta time. How much time has passed 
		// since it was last calculated (in seconds) and restart the clock.
		deltaTime = clock.restart().asSeconds();


		//Game States
		switch (gameState.getCurrentState())
		{
		case(State::CONTROLS):
			controls.update(deltaTime);
			controls.handleInput(deltaTime);
			controls.render();
			break;
		case(State::FINAL):
			final.update(deltaTime);
			final.handleInput(deltaTime);
			final.render();
			break;
		case(State::MAINMENU):
			if (level.getreset())				   //
			{									   //
				level.levelreset();				   //Helps in resetting level to main menu
			}									   //
			mainmenu.update(deltaTime);			   //
			mainmenu.handleInput(deltaTime);	   
			mainmenu.render();					   
			break;
		case(State::LEVEL):
			level.update(deltaTime);
			level.handleInput(deltaTime);
			level.render();
			break;
		case(State::END):
			end.update(deltaTime);
			end.handleInput(deltaTime);
			end.render();
			break;
		case(State::PAUSE):
			level.handleInput(deltaTime);
			level.render();
			break;
		case(State::CREDITS):
			break;

		}


		// Update input class, handle pressed keys
		// Must be done last.
		input.update();





	}

}