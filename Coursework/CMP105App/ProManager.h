#pragma once
#include "Projectile.h"

class ProManager :public GameObject
{
public:
	ProManager();//contructor for class
	~ProManager();//destructor for class

	//Declaration of Public functions
	void gen(); //Generates projectile
	void update(float dt); //updates the projectile
	void ProTest(); //Tests if the projectile is there or not
	void render(sf::RenderWindow* window); //draws the projectile onto the screen
	void ProSpeed(sf::Vector2f spe); //Has the speed of the projectile
	void ProPos(int a, int b); //sets the position of the projectile

	std::vector <Projectile>& getProjectiles();  //Vector for the projectile

private:
	sf::Texture sprt;
	sf::Vector2f dest;
	AudioManager audio; //sound for the projectile
	std::vector <Projectile> projectiles;
	int genx; //this variable helps in identifying x coordinate of projectile in relation to character 
	int geny; //this variable helps in identifying y coordinate of projectile in relation to character 


};
