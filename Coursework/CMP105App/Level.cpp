#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	//Setting window and display
	display.reset(sf::FloatRect(360.f, 0.f, 1200.f, 800.f));
	display1.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));

	
	fnt5.loadFromFile("font/Future Worlds.ttf");
	scr.setFont(fnt5);
	scr.setString("SCORE:");
	scr.setCharacterSize(80);
	scr.setPosition(10, 10);
	scr.setFillColor(sf::Color::White);

	//Initialisation for playable character
	TexOfChar.loadFromFile("gfx/mechsheet.png");
	character.setInput(in);
	character.setTexture(&TexOfChar);
	character.ProFire(&Projectiles);
	character.CharPos(hwnd);
	character.setAlive(true);
	character.setOrigin(50, 50);
	character.setSize(sf::Vector2f(120, 120));
	character.setCollider(true);
	character.setCollisionBox(0, 0, 100, 100);
	character.setPosition(700, 350);

	//Wallpaper
	bgimTex.loadFromFile("gfx/wpbg.png");
	bgim.setSize(sf::Vector2f(2159 * 2, 3839 * 2));
	bgim.setPosition(-1439, -2559);
	bgim.setTexture(&bgimTex);

	//Generating Opponents
	int a = 0;
	while (a < 35)
	{
		Opps.OppGen();
		a++;
	}


	//Secondary Obstacles
	
	int i = 0;
	while( i < 4)
	{
		obs.setSize(sf::Vector2f(0, 0));
		obs.setCollisionBox(0, 0, 11, 863);
		obs.setCollider(true);
		secObs.push_back(obs);
		i++;
	}
	//position of secondary obstacles
	secObs[0].setPosition(sf::Vector2f(145, 1081));
	secObs[1].setPosition(sf::Vector2f(1113, 1081));
	secObs[2].setPosition(sf::Vector2f(145, 1949));
	secObs[3].setPosition(sf::Vector2f(1113, 1949));
	//Primary Obstacles
	
	int j = 0;
	while( j < 4)
	{
		obs1.setSize(sf::Vector2f(0, 0));
		obs1.setCollisionBox(0, 0, 11, 863);
		obs1.setCollider(true);
		frontObs.push_back(obs1);
		j++;
	}


	//Position of Primary Obstacles
	frontObs[0].setPosition(sf::Vector2f(326, 228));
	frontObs[1].setPosition(sf::Vector2f(1100, 230));
	frontObs[2].setPosition(sf::Vector2f(132, 1092));
	frontObs[3].setPosition(sf::Vector2f(1292, 1092));


	//Map
	carrierTex.loadFromFile("gfx/carrier.png");
	carrier.setSize(sf::Vector2f(1439, 2559));
	carrier.setPosition(0, 0);
	carrier.setTexture(&carrierTex);

	//Aim
	//Collision box at the end
	aim.setPosition(650, 2351);
	aim.setSize(sf::Vector2f(0, 0));
	aim.setCollisionBox(0, 0, 150, 150);

	//obstacles on the map
	std::vector<GameObject> block;
	int z = 0;
	while( z < 15)
	{
		blocks.setSize(sf::Vector2f(65, 65));
		blocks.setCollisionBox(0, 0, 65, 65);
		blocks.setCollider(true);
		blocks.setFillColor(sf::Color::Transparent);
		block.push_back(blocks);
		z++;
	};			


	//Garbage 1
	PrimPlot.setTileSet(block);											

	sf::Vector2u PlotDim1(10, 3);
	
																		
	std::vector<int> Plot1 =
	{
		0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0
	};
	PrimPlot.setTileMap(Plot1, PlotDim1);
	PrimPlot.setPosition(sf::Vector2f(340, 190));
	PrimPlot.buildLevel();

	//Garbage 2																	
	leftCont.setTileSet(block);												   
																	
	sf::Vector2u rec(4, 2);
																			
	std::vector<int> recplot = {
		0,0,0,0,
		0,0,0,0
	};
	leftCont.setTileMap(recplot, rec);
	leftCont.setPosition(sf::Vector2f(342, 774));
	leftCont.buildLevel();

	//Tank
	rightCont.setTileSet(block);											
	rightCont.setTileMap(recplot, rec);
	rightCont.setPosition(sf::Vector2f(844, 774));
	rightCont.buildLevel();



	//rocks																	
	rocks.setTileSet(block);

	sf::Vector2u recmea(11, 1);
																			
	std::vector<int> recplot2 = {
		0,0,0,0,0,0,0,0,0,0,0
	};
	rocks.setTileMap(recplot2, recmea);
	rocks.setPosition(sf::Vector2f(539, 1355));
	rocks.buildLevel();


	//End rocks																
	plotComp1.setTileSet(block);											
																		
	sf::Vector2u plottank(3, 1);
																			
	std::vector<int> plottank2 = {
		0,0,0
	};
	plotComp1.setTileMap(plottank2, plottank);
	plotComp1.setPosition(sf::Vector2f(342, 960));
	plotComp1.buildLevel();



																			
	plotComp3.setTileSet(block);											
																		
	sf::Vector2u rockmea(11, 2);
																			
	std::vector<int> rockmea1 = {
		0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,
	};
	plotComp3.setTileMap(rockmea1, rockmea);
	plotComp3.setPosition(sf::Vector2f(226, 1610));
	plotComp3.buildLevel();


	//Audio
	
	
	aud->addSound("sfx/char_death.ogg", "death");
	aud->addMusic("sfx/level_theme.ogg", "maintheme");

	
}

Level::~Level()
{

}


void Level::handleInput(float dt)
{
	character.handleInput(dt);


	if (input->isKeyDown(sf::Keyboard::P))
	{

		if (gameState->getCurrentState() != State::PAUSE)
		{
			input->setKeyUp(sf::Keyboard::P);
			gameState->setCurrentState(State::PAUSE);
		}
		else
		{
			input->setKeyUp(sf::Keyboard::P);
			gameState->setCurrentState(State::LEVEL);
		}
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		character.charReset();

	}


	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}
}


void Level::update(float dt)
{


	if (audio->getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio->playMusicbyName("maintheme");
	}


	std::string pts = std::to_string(character.scoreGet());
	scr.setString(pts);


	character.update(dt);
	Opps.update(dt);
	Projectiles.update(dt);


	display.setCenter(character.getPosition().x, character.getPosition().y);



	if (!character.isAlive())
	{
		audio->stopAllMusic();
		c = true;
		gameState->setCurrentState(State::END);
		
	}

	//Collision detection between character and opponent
	int x = 0;
	while( x < Opps.OppGetter().size())
	{
		if (Opps.OppGetter().at(x).isCollider())
		{
			if (Collision::checkBoundingBox(&Opps.OppGetter().at(x), &character))
			{
				audio->playSoundbyName("death");
				character.setAlive(false);
			}
		}x++;
	}

	//Collision between character and aim
	if (Collision::checkBoundingBox(&character, &aim))
	{
		audio->stopAllMusic();
		c = true;
		gameState->setCurrentState(State::FINAL);
	}


	//Collision Detection for walls
	std::vector<GameObject>* front = frontObsgetter();
	int x1 = 0;
	while(x1 < front->size())
	{
		if ((*front)[x1].isCollider())
		{
			for (int y = 0; y < Opps.OppGetter().size(); y++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*front)[x1]))
				{
					Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
				}

				for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
				{
					if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*front)[x1]))
					{
						Projectiles.getProjectiles().at(z).ColRes(NULL);
					}
				}
			}
		}x1++;
	}

	

	//Garbage1
	std::vector<GameObject>* garb1 = PrimPlot.getLevel();
	int x2 = 0;
	while(x2 < (int)garb1->size())
	{
		if ((*garb1)[x2].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*garb1)[x2]))
			{
				character.ColRes(&(*garb1)[x2]);
			}
			for (int y = 0; y < Opps.OppGetter().size(); y++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*garb1)[x2]))
				{
					Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
				}
			}
			for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
			{
				if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*garb1)[x2]))
				{
					Projectiles.getProjectiles().at(z).ColRes(NULL);
				}
			}
		}x2++;
	}

	//Garbage
	std::vector<GameObject>* garb = leftCont.getLevel();
	int x3 = 0;
	while( x3 < (int)garb->size())
	{
		if ((*garb)[x3].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*garb)[x3]))
			{
				character.ColRes(&(*garb)[x3]);
			}
			for (int y = 0; y < Opps.OppGetter().size(); y++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*garb)[x3]))
				{
					Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
				}
			}
			for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
			{
				if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*garb)[x3]))
				{
					Projectiles.getProjectiles().at(z).ColRes(NULL);
				}
			}
		}x3++;
	}

	//Tank
	std::vector<GameObject>* tank = rightCont.getLevel();
	int x4 = 0;
	while( x4 < (int)tank->size())
	{
		if ((*tank)[x4].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*tank)[x4]))
			{
				character.ColRes(&(*tank)[x4]);
			}
			for (int y = 0; y < Opps.OppGetter().size(); y++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*tank)[x4]))
				{
					Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
				}
			}
			for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
			{
				if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*tank)[x4]))
				{
					Projectiles.getProjectiles().at(z).ColRes(NULL);
				}
			}
		}x4++;
	}

	//Tank2 Collision
	std::vector<GameObject>* tank2 = plotComp1.getLevel();
	int x5 = 0;
	while( x5 < (int)tank2->size())
	{
		if ((*tank2)[x5].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*tank2)[x5]))
			{
				character.ColRes(&(*tank2)[x5]);
			}
			for (int y = 0; y < Opps.OppGetter().size(); y++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*tank2)[x5]))
				{
					Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
				}
			}
			for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
			{
				if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*tank2)[x5]))
				{
					Projectiles.getProjectiles().at(z).ColRes(NULL);
				}
			}
		}x5++;
	}






	//Rocks and debris
	std::vector<GameObject>* rck = plotComp3.getLevel();
	int x6 = 0;
	while(x6 < (int)rck->size())
	{
		if ((*rck)[x6].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*rck)[x6]))
			{
				character.ColRes(&(*rck)[x6]);
			}
		}
		for (int y = 0; y < Opps.OppGetter().size(); y++)
		{
			if (Collision::checkBoundingBox(&Opps.OppGetter().at(y), &(*rck)[x6]))
			{
				Opps.OppGetter().at(y).setVelocity(-Opps.OppGetter().at(y).getVelocity());
			}
		}
		for (int z = 0; z < Projectiles.getProjectiles().size(); z++)
		{
			if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(z), &(*rck)[x6]))
			{
				Projectiles.getProjectiles().at(z).ColRes(NULL);
			}
		}x6++;
	}

	//Rocks and debris Collision
	std::vector<GameObject>* box3 = rocks.getLevel();
	int x7 = 0;
	while( x7 < (int)box3->size())
	{
		if ((*box3)[x7].isCollider())
		{
			if (Collision::checkBoundingBox(&character, &(*box3)[x7]))
			{
				character.ColRes(&(*box3)[x7]);
			}
			for (int j = 0; j < Opps.OppGetter().size(); j++)
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(j), &(*box3)[x7]))
				{
					Opps.OppGetter().at(j).setVelocity(-Opps.OppGetter().at(j).getVelocity());//Changes direction
				}
			}
			for (int k = 0; k < Projectiles.getProjectiles().size(); k++)
			{
				if (Collision::checkBoundingBox(&Projectiles.getProjectiles().at(k), &(*box3)[x7]))
				{
					Projectiles.getProjectiles().at(k).ColRes(NULL);
				}
			}
		}x7++;
	}

	//Collision detection between opponent and projectiles
	int x8 = 0;
	while( x8 < Opps.OppGetter().size())
	{
		for (int y = 0; y < Projectiles.getProjectiles().size(); y++)
		{
			if (Projectiles.getProjectiles().at(y).isCollider() && Opps.OppGetter().at(x8).isCollider())
			{
				if (Collision::checkBoundingBox(&Opps.OppGetter().at(x8), &Projectiles.getProjectiles().at(y)))
				{
					Projectiles.getProjectiles().at(y).ColRes(NULL);
					character.scoreAdd();
					Opps.OppGetter().at(x8).ColRes(NULL, 10);
				}
			}
		}
		x8++;
	}





}
 //Resetting the level
void Level::levelreset()
{
	c = false;
	character.charReset();
	Opps.resetOpp();
}
//function for setting
bool Level::getreset()
{
	return c;
}

// Render level
void Level::render()
{
	beginDraw();
	window->setView(display);
	window->draw(bgim);
	window->draw(carrier);
	PrimPlot.render(window);
	leftCont.render(window);
	rightCont.render(window);
	plotComp1.render(window);
	plotComp2.render(window);
	plotComp3.render(window);
	rocks.render(window);
	window->draw(character);
	Opps.render(window);
	Projectiles.render(window);
	window->setView(display1);
	window->draw(scr);
	endDraw();
}

void Level::beginDraw()
{}

void Level::endDraw()
{

	window->display();

}
