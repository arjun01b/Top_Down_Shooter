#include "Opp.h"

Opp::Opp()
{
	//Sets animation frames
	ani.addFrame(sf::IntRect(60, 0, 69, 64)); //
	ani.addFrame(sf::IntRect(139, 0, 73, 64)); //
	ani.setFrameSpeed(1.f / 2.f); //
}

Opp::~Opp()
{

}
void Opp::ColRes(GameObject* col, int x)
{
	OppHea(OppHeaGetter() - x);
}

int Opp::OppHeaGetter()
{
	return life;

}

void Opp::OppHea(int l)
{

	life = l;

}
void Opp::render()
{

}

void Opp::update(float dt)
{
	move(velocity * dt);
	ani.animate(dt);
	setTextureRect(ani.getCurrentFrame());


	// change dir when reaching end
	if (getPosition().x < 91)
	{
		velocity = -velocity;
	}
	if (getPosition().x > 1201)
	{
		velocity = -velocity;
	}
	

	if (velocity.x < 0)
	{
		ani.setFlipped(true); //invert the sprite if going left
	}
	else
	{
		ani.setFlipped(false); //invert the sprite if going right
	}
}
void Opp::handleInput(float dt)
{

}

