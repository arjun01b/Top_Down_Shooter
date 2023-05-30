#include"Controls.h"

Controls::Controls(sf::RenderWindow* win, Input* in, GameState* gs)
{
    window = win;
    input = in;
    gamestate = gs;

    
    //Text for controls
    style.loadFromFile("font/Future Worlds.ttf");
    title.setFont(style);
    title.setString("CONTROLS :");
    title.setCharacterSize(40);
    title.setFillColor(sf::Color(150, 80, 0));
    title.setPosition(15,0);
    //Text
    dir.setFont(style);
    dir.setString("FOR MOVEMENT: \n W \n A\n S\n D \n use mouse to aim ");
    dir.setCharacterSize(40);
    dir.setFillColor(sf::Color(150, 80, 0)); //CONTROLS
    dir.setPosition(0, 75);
    //Text
    des.setFont(style);
    des.setString("LSHIFT FOR SHOOTING\n\n B TO BEGIN GAME \n\nP TO PAUSE THE GAME \n\n BACKSPACE TO GO BACK");
    des.setCharacterSize(40);
    des.setFillColor(sf::Color(150, 80, 0)); //DESCRIPTION
    des.setPosition(600, 40);
    //Text
    Ene.loadFromFile("gfx/tanksprite.png");
    ene.setSize(sf::Vector2f(144, 104)); //ENEMY SPRITE
    ene.setPosition(350, 460);
    ene.setTexture(&Ene);
    //Destination
    Dest.loadFromFile("gfx/destination1.png");
    dest.setSize(sf::Vector2f(230, 128));
    dest.setPosition(600, 375);
    dest.setTexture(&Dest);
    //Text
    aim.setFont(style);
    aim.setString("REACH TARGET TO END THE GAME\n\nAVOID THE TANKS");
    aim.setCharacterSize(40);
    aim.setFillColor(sf::Color(150, 80, 0)); //GAME OBJECTIVE
    aim.setPosition(0, 400);


}

Controls::~Controls()
{
}

void Controls::update(float dt)
{

}

void Controls::render()
{
    beginDraw();
    window->draw(title);
    window->draw(dir);
    window->draw(des);
    window->draw(ene);
    window->draw(dest);
    window->draw(aim);

    endDraw();

}

void Controls::handleInput(float dt)
{
    if (input->isKeyDown(sf::Keyboard::B))
    {
        input->setKeyUp(sf::Keyboard::B);
        
        gamestate->setCurrentState(State::LEVEL);
    }

    if (input->isKeyDown(sf::Keyboard::BackSpace))
    {
        input->setKeyUp(sf::Keyboard::BackSpace);
        gamestate->setCurrentState(State::MAINMENU);
    }

    if (input->isKeyDown(sf::Keyboard::E))
    {
        input->setKeyUp(sf::Keyboard::E);
        window->close();
    }
}


void Controls::beginDraw()
{
    window->clear(sf::Color::Black);

}

void Controls::endDraw()
{
    window->display();
}