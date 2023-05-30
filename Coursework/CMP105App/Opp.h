#pragma once
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
#include "Framework/VectorHelper.h"

class Opp : public GameObject
{
public:
	Opp();
	~Opp();

	void update(float dt); //
	void OppHea(int l); //
	int  OppHeaGetter(); //
	void ColRes(GameObject* col, int x); //
	void handleInput(float dt);
	void render();

private:
	Animation ani;
	int life;


};