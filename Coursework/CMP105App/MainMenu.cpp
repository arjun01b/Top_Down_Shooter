#include"MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow* win, Input* in, GameState* gs)
{
	gameState = gs;										  //
	input = in;											  //
	window = win;										  //
														  //
														  //
	//Background										  //
	backgroundImage.loadFromFile("gfx/menusprite.png");	  //
	background.setSize(sf::Vector2f(1200, 600));		  //
	background.setPosition(0, 0);						  //
	background.setTexture(&backgroundImage);			  //
														  //
	//Text												  //
	if (!ft.loadFromFile("font/Future Worlds.ttf"))			  //
	{													  //
		std::cout << "Error loading font";			  //
	}													  //
	txt.setFont(ft);									  //
	txt.setString("MECH VS TANKS");					  //
	txt.setCharacterSize(100);							  //
	txt.setFillColor(sf::Color(150, 80, 0));			  //
	txt.setPosition(200, 0);							  //
														  //
						  
}

MainMenu::~MainMenu()
{

}

void MainMenu::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::CONTROLS); 
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}





}

void MainMenu::update(float dt)
{

}

void MainMenu::render()
{
	beginDraw();
	window->draw(background);
	window->draw(txt);
	
	endDraw();
}

void MainMenu::beginDraw()
{
	window->clear(sf::Color::Black);
}

void MainMenu::endDraw()
{
	window->display();
}