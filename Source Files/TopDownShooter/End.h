#pragma once

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
#include "Character.h"


class End
{
public:

	End(sf::RenderWindow* win, Input* in, GameState* gs);
	~End();
	void render();
	void handleInput(float dt);
	void update(float dt);

private:
	//
	void beginDraw();
	void endDraw();


	//variables
	GameState* state;
	AudioManager aud;
	GameObject img;
	sf::RenderWindow* wnd;
	Input* ipt;
	//
	sf::Texture background;
	sf::Text txt2;
	sf::Font fnt1;
	sf::Text txt1;
};