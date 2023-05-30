#pragma once
#include<SFML/Graphics.hpp>
#include"Framework/AudioManager.h"
#include "Framework/GameState.h"
#include "Framework/GameObject.h"
#include"Framework/Input.h"
#include<string>
#include<iostream>

class Final
{
public:
	Final(sf::RenderWindow* win, Input* in, GameState* gs);
	~Final();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	void beginDraw();
	void endDraw();

	Input* input;
	AudioManager audio;
	GameState* gamestate;
	sf::RenderWindow* window;

	GameObject wallpaper;
	sf::Texture wp;

	sf::Font fnt3;
	sf::Text txt4;


};