#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"

class MainMenu
{
public:
	MainMenu(sf::RenderWindow* win, Input* in, GameState* gs);
	~MainMenu();

	void update(float dt);
	void render();
	void handleInput(float dt);
private:
	void endDraw();
	void beginDraw();

	// Default variables for class.
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager audio;
	GameObject background;
	sf::Texture backgroundImage;
	sf::Text txt;
	sf::Text txt1;
	sf::Font ft;

};
