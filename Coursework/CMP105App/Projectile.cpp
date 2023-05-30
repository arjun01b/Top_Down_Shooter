#include "Projectile.h"

//Calling Constructor for class
Projectile::Projectile()
{

}

//Calling Destructor for class
Projectile::~Projectile()
{

}

//Updating the movement of
//projectile in relation to velocity
void Projectile::update(float dt)
{

	move(velocity * dt);

}

//Detects Collision and response
void Projectile::ColRes(GameObject* collider)
{

	setAlive(false);//turns the projectile to get destroyed
	setCollider(false);//setting the collider to false stops the collision with next collider

}
void Projectile::handleInput(float dt)
{

}

void Projectile::render()
{

}