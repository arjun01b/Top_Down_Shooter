#pragma once

#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include"Framework/TileMap.h"
#include"Framework/Collision.h"
#include"OppManager.h"
#include"ProManager.h"


class Level : public BaseLevel
{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();
	void levelreset();
	bool getreset();

	std::vector<GameObject>* frontObsgetter() { return &frontObs; };
	std::vector<GameObject>* secObsgetter() { return &secObs; };

private:

	// Default variables for level class.
	sf::RenderWindow* wnd;
	GameState* gS;
	AudioManager aud;
	Input* inp;

	//


	sf::View display;
	sf::View display1;

	//Map

	GameObject bgim;
	GameObject carrier;
	sf::Texture bgimTex;
	sf::Texture carrierTex;
	GameObject blocks;

	OppManager Opps;
	ProManager Projectiles;
	std::vector<GameObject> frontObs;
	std::vector<GameObject> secObs;
	GameObject obs1;
	GameObject aim;
	sf::Font fnt5;
	sf::Text scr;
	GameObject obs;

	//
	Character character;
	sf::Texture TexOfChar;


	//Tile
	TileMap PrimPlot;
	TileMap rocks;
	TileMap leftCont;
	TileMap rightCont;
	TileMap plotComp1;
	TileMap plotComp2;
	TileMap plotComp3;


	bool c=false;

	void beginDraw();
	void endDraw();



};