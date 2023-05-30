#include"OppManager.h"

OppManager::OppManager()
{
	sprite.loadFromFile("gfx/tanksheet.png");//Loads sprite

	srand(time(0)); //


	//
	int v = 0;
	while( v < 40) //
	{
		Opps.push_back(Opp());
		Opps[v].setAlive(false);
		Opps[v].setTexture(&sprite);
		Opps[v].setSize(sf::Vector2f(139, 99));
		Opps[v].OppHea(10);
		Opps[v].setCollisionBox(0, 0, 139, 99);
		Opps[v].setCollider(false);
		Opps[v].setPosition(349 + (rand() % (895 - 349 + 1)), 459 + (rand() % (655 - 455 + 1)));
		Opps[v].setVelocity(300, 0);
		v++;
	}
	int p = 0;
	while (p < 20) //						//
	{										//
		Opps[p].setPosition(201, 1161);		//
		Opps[p].setVelocity(250, 95);		//
		Opps[p + 1].setVelocity(500, 0);	//
		p++;								//
	}
	
	int z = 0;
	while( z < 22)
	{
		Opps[z].setPosition(195 + (rand() % (1095 - 195 + 1)), 1415 + (rand() % (1450 - 1415 + 1)));
		Opps[z].setVelocity(700, 10);
		z++;
	}

	int f = 0;
	while( f < 18)
	{
		Opps[f].setPosition(115 + (rand() % (1195 - 115 + 1)), 1961 + (rand() % (2395 - 1961 + 1)));
		Opps[f].setVelocity(450, 0);
		f++;
	}



}

OppManager::~OppManager()
{

}

void OppManager::update(float dt)
{										  //
	int u = 0;							  // 
	while (u < Opps.size())				  //
	{									  //
										  //
		if (Opps[u].isAlive())			  //
		{								  //
			Opps[u].update(dt);			  //
		}								  //
		u++;							  //
										  //
	}									  //
										  //
	OppTest();
}

void OppManager::OppTest()
{
	int t = 0;
	while( t < Opps.size())
	{
		if (Opps[t].isAlive())
		{
			if (Opps[t].OppHeaGetter() <= 0) //
			{
				Opps[t].setCollider(false); //
				Opps[t].setAlive(false); //
			}
		}
		t++;

	}
}

void OppManager::OppGen()
{
	int g = 0;
	while( g < Opps.size())
	{
		if (!Opps[g].isAlive())
		{
			Opps[g].setAlive(true);
			Opps[g].setCollider(true);
			return;
		}
		g++;
	}

}
void OppManager::resetOpp()
{
	for (int i = 0; i < Opps.size(); i++)
	{
		Opps[i].setAlive(true);
		Opps[i].setCollider(true);
		Opps[i].OppHea(10);
	}
}

void OppManager::render(sf::RenderWindow* window)
{
	int e = 0;
	while( e < Opps.size())
	{
		if (Opps[e].isAlive())
		{
			window->draw(Opps[e]); 
		}
		e++;
	}
}

std::vector<Opp>& OppManager::OppGetter()
{
	return Opps;
}