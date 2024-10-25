#include"Character.h"

Character::Character()
{

	
	ani1.addFrame(sf::IntRect(0, 0, 77, 63)); 
	ani1.addFrame(sf::IntRect(77, 0, 79, 64));
	ani1.setFrameSpeed(1.f / 5.f); 

	scr = 0;
}

Character::~Character()
{

}

void Character::update(float dt)
{
	move(velocity * dt);
	setTextureRect(ani1.getCurrentFrame());


	if (getPosition().y < 1092)
	{
		if (getPosition().x < 340)
		{
			setPosition(340, getPosition().y);
		}

		if (getPosition().x > 1099)
		{
			setPosition(1099, getPosition().y);
		}
	}

	if (getPosition().x < 340)
	{
		if (getPosition().y < 1080)
		{
			setPosition(getPosition().x, 1080);
		}
	}

	if (getPosition().x > 1102)
	{
		if (getPosition().y < 1090)
		{
			setPosition(getPosition().x, 1090);
		}
	}

	if (getPosition().x < 146)
	{
		setPosition(146, getPosition().y);
	}
	if (getPosition().x > 1300)
	{
		setPosition(1300, getPosition().y);
	}
	if (getPosition().y > 2510)
	{
		setPosition(getPosition().x, 2510);
	}

	if (velocity.x > 0.0)
	{
		ani1.animate(dt);
		setTextureRect(ani1.getCurrentFrame());
	}
	else if (velocity.y > 0.0)
	{
		ani1.animate(dt);
		setTextureRect(ani1.getCurrentFrame());
	}
	else if (velocity.x < 0.0)
	{
		ani1.animate(dt);
		setTextureRect(ani1.getCurrentFrame());
	}
	
	else if (velocity.y < 0.0)
	{
		ani1.animate(dt);
		setTextureRect(ani1.getCurrentFrame());
	}

	else
	{
		ani1.reset();
		setTextureRect(ani1.getCurrentFrame());
	}

	int Y = input->getMouseY();
	int X = input->getMouseX();
	

	sf::Vector2f Pos_char = static_cast<sf::Vector2f>(window->getSize());
	
	float y = (Y - (Pos_char.y / 2.f));
	float x = (X - (Pos_char.x) / 2.f);
	float a = ((atan2(y, x)) * (180 / 3.14));
	setRotation(a);




}

void Character::ColRes(GameObject* collider)
{


	float Ycol = collider->getPosition().y + (collider->getSize().y / 2);
	float Xcol = collider->getPosition().x + (collider->getSize().x / 2);
	float Ychar = getPosition().y;
	float Xchar = getPosition().x;

	float Ydis = (abs(Ycol - Ychar));
	float Xdis = (abs(Xcol - Xchar));


	if (abs(Ydis) < abs(Xdis))
	{
		if (Xcol > Xchar)
		{
			velocity.x = 0;
			setPosition(abs(Xcol - getSize().x), getPosition().y);
		}
		if (Xcol < Xchar)
		{
			velocity.x = 0;
			setPosition(abs(Xcol + getSize().x), getPosition().y);
		}

	}
	else
	{
		if (Ycol > Ychar)
		{
			velocity.y = 0;
			setPosition(getPosition().x, abs(Ycol - getSize().y));
		}
		else if (Ycol < Ychar)
		{
			velocity.y = 0;
			setPosition(getPosition().x, abs(Ycol + getSize().y));
		}
	}

}

void Character::scoreAdd()
{
	scr = scr + 5;
}

int Character::scoreGet()
{

	return scr;

}


void Character::ProFire(ProManager* fp)
{
	Projectiles = fp;
}

void Character::CharPos(sf::RenderWindow* win)
{
	window = win;
}

void Character::handleInput(float dt)
{


	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y = -350;
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x = -350;
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y = 350;
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x = 350;
	}

	else
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	if (input->isKeyDown(sf::Keyboard::LShift))
	{
		input->setKeyUp(sf::Keyboard::LShift);


		int Ycur = input->getMouseY();
		int Xcur = input->getMouseX();

		sf::Vector2f pos = static_cast<sf::Vector2f>(window->getSize());
		sf::Vector2f cur(Xcur, Ycur);
		sf::Vector2f aim = cur - (pos / 2.f);
		Projectiles->ProSpeed(aim);
		Projectiles->ProPos(getPosition().x, getPosition().y);
		Projectiles->gen();

	}


}

void Character::charReset()
{
	scr = 0;
	setPosition(700,350);
	setAlive(true);

}
void Character::render()
{

}