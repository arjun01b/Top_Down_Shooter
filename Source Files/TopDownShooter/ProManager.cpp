#include"ProManager.h"

//Calling constructor
ProManager::ProManager()
{
	sprt.loadFromFile("gfx/projectile1.png");//Loads image for the projectile
	audio.addSound("sfx/projectile_hit.ogg", "fire");//Makes a firing sound

	//Setting properties for the Projectile
	int x = 0;
	while( x< 50)
	{
		projectiles.push_back(Projectile()); //
		projectiles[x].setAlive(false); //
		projectiles[x].setTexture(&sprt); //
		projectiles[x].setSize(sf::Vector2f(50, 50)); //
		projectiles[x].setCollisionBox(0, 0, 50, 50); //
		projectiles[x].setCollider(false); //
		x++;

	}
	
}

//Calling Destructor
ProManager::~ProManager()
{

}


void ProManager::update(float dt)
{
	int d = 0;
	while( d < projectiles.size())
	{
		if (projectiles[d].isAlive())
		{
			projectiles[d].update(dt);
		}

		d++;


	}
	
	ProTest();
}


void ProManager::ProSpeed(sf::Vector2f spe)
{
	dest = spe; //
}

//Generates the projectile
void ProManager::gen()
{
	int x = 0;
	while (x < projectiles.size())
	{
		if (!projectiles[x].isAlive())
		{
			projectiles[x].setAlive(true);
			projectiles[x].setPosition(genx, geny); //generates projectile regarding the position of character
			projectiles[x].setVelocity(dest); //speed of the projectile is determined
			projectiles[x].setCollider(true);
			audio.playSoundbyName("fire");
			return;
		}
		x++;
	}
}

void ProManager::render(sf::RenderWindow* window)
{
	int h = 0;
	while(h < projectiles.size())
	{
		if (projectiles[h].isAlive())
		{
			window->draw(projectiles[h]); //generates bullet on screen
		}
		h++;
	}
}

void ProManager::ProTest()
{
	int j=0;
	while( j < projectiles.size())
		// Projectile is destroyed if it goes out of carrier
	{
		if (projectiles[j].isAlive())
		{
			if (projectiles[j].getPosition().x < 0)
			{
				projectiles[j].setAlive(false);
			}
			if (projectiles[j].getPosition().x > 1439) // for x coordinate
			{
				projectiles[j].setAlive(false);
			}
			if (projectiles[j].getPosition().y < 0)
			{
				projectiles[j].setAlive(false);
			}
			if (projectiles[j].getPosition().y > 2559) // for y coordinate
			{
				projectiles[j].setAlive(false);
			}
		}
		j++;
	}

}

void ProManager::ProPos(int a, int b)
{


	genx = a; //
	geny = b;
}




std::vector<Projectile>& ProManager::getProjectiles()
{
	return projectiles; // for level class
}