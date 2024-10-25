#pragma once
#include"Opp.h"

class OppManager
{
public:
	OppManager();
	~OppManager();


	// Declaration of public functions

	void update(float dt); //
	void OppTest(); //
	void OppGen(); //
	void render(sf::RenderWindow* window); //
	void resetOpp();

	std::vector <Opp>& OppGetter();
protected:
	std::vector <Opp> Opps;//Vector of enemy used in manager class
	sf::Texture sprite;//Texture


};