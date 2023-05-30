#pragma once
#include "Framework/AudioManager.h"
#include "Framework/Animation.h"
#include "Framework/GameObject.h"
#include "Framework/VectorHelper.h"

class Projectile : public GameObject
{
public:
	Projectile();//constructor for class
	~Projectile();//destructor for class


	void ColRes(GameObject* collider);//detects damage
	void update(float dt);//function to update time
	void handleInput(float dt);
	void render();

};