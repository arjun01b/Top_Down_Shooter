#pragma once


#include<SFML/Graphics.hpp>
#include"Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include"Framework/Input.h"
#include<string>
#include<iostream>

class Controls
{
public:
	Controls(sf::RenderWindow* win, Input* in, GameState* gs);
	~Controls();


	void render();
	void update(float dt);
	void handleInput(float dt);

private:
	void beginDraw();
	void endDraw();

	//
	sf::RenderWindow* window;
	AudioManager audio;
	GameState* gamestate;
	Input* input;


	//
	GameObject ene;
	sf::Texture Ene;
	GameObject dest;
	sf::Texture Dest;


	//Text
	sf::Font style;
	sf::Text title;
	sf::Text dir;
	sf::Text des;
	sf::Text aim;



};