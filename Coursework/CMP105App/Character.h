#pragma once


#include "ProManager.h"
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include <SFML/Graphics.hpp>
#include "Framework/VectorHelper.h"

class Character : public GameObject
{
public:
	Character();
	~Character();
	void update(float dt);
	void ColRes(GameObject* collider);
	void scoreAdd();
	int scoreGet();
	void CharPos(sf::RenderWindow* win);
	void ProFire(ProManager* fp);
	void handleInput(float dt);
	void render();
	void charReset();

private:

	ProManager* Projectiles;
	sf::RenderWindow* window;
	int scr;
	Animation ani1;


};
