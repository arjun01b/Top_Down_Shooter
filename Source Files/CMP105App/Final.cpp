#include"Final.h"

Final::Final(sf::RenderWindow* win, Input* in, GameState* gs)
{
	window = win;
	input = in;
	gamestate = gs;


	// WALLPAPER
	wp.loadFromFile("gfx/winstate.png");
	wallpaper.setSize(sf::Vector2f(1000, 800));
	wallpaper.setPosition(0, 0);
	wallpaper.setTexture(&wp);


	//TEXT
	fnt3.loadFromFile("font/Future Worlds.ttf");
	txt4.setFont(fnt3);
	txt4.setString("CONGRATULATIONS YOU WON\n\nPRESS ENTER TO RESTART \n\n ESC TO EXIT");
	txt4.setCharacterSize(50);
	txt4.setFillColor(sf::Color(150, 80, 0));
	txt4.setPosition(100, 400);


	audio.addMusic("sfx/level_win.ogg", "wintheme");
}

Final::~Final()
{

}

void Final::update(float dt)
{
	if (audio.getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		audio.playMusicbyName("wintheme");
	}
}

void Final::render()
{
	beginDraw();
	window->draw(wallpaper);
	window->draw(txt4);


	endDraw();

}

void Final::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		audio.stopAllMusic();
		gamestate->setCurrentState(State::MAINMENU);
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
}

void Final::beginDraw()
{
	window->clear(sf::Color::Black);
}

void Final::endDraw()
{
	window->display();
}

