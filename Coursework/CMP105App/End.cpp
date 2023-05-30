#include"End.h"

End::End(sf::RenderWindow* win, Input* in, GameState* gs)
{
	wnd = win;
	ipt = in;
	state = gs;

	//Font for end screen
	fnt1.loadFromFile("font/Future Worlds.ttf");
	txt1.setFont(fnt1);
	txt1.setString("GAME OVER");
	txt1.setCharacterSize(40);
	txt1.setFillColor(sf::Color(150, 80, 0));
	txt1.setPosition(350, 0);

	//Font for end screen
	fnt1.loadFromFile("font/Future Worlds.ttf");
	txt2.setFont(fnt1);
	txt2.setString("PRESS ENTER TO RESTART OR \n\n ESCAPE TO EXIT");
	txt2.setCharacterSize(40);
	txt2.setFillColor(sf::Color(150,80,0));
	txt2.setPosition(250, 400);



	//Wallpaper
	background.loadFromFile("gfx/gameover1.png");
	img.setSize(sf::Vector2f(1000, 800));
	img.setPosition(0, 70);
	img.setTexture(&background);

	//Adding music
	aud.addMusic("sfx/level_fail.ogg", "gotheme");

}

End::~End()
{

}


void End::update(float dt)
{
	if (aud.getMusic()->getStatus() == sf::SoundSource::Stopped)
	{
		aud.playMusicbyName("gotheme");
	}
}

void End::handleInput(float dt)
{
	if (ipt->isKeyDown(sf::Keyboard::Enter))
	{
		ipt->setKeyUp(sf::Keyboard::Enter);
		aud.stopAllMusic();
		state->setCurrentState(State::MAINMENU);
		
	}

	if (ipt->isKeyDown(sf::Keyboard::Escape))
	{
		ipt->setKeyUp(sf::Keyboard::Escape);
		wnd->close();
	}
}

void End::render()
{
	beginDraw();
	wnd->draw(txt1);
	wnd->draw(txt2);
	wnd->draw(img);
	endDraw();
}

void End::beginDraw()
{
	wnd->clear(sf::Color::Black);
}

void End::endDraw()
{
	wnd->display();
}
