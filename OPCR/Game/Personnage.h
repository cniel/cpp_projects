#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;


class Personnage
{

public:
	Personnage();
	Personnage(std::string name);
	Personnage(std::string name, int life);
	//Personnage(std::string name, std::string weapon, int strength, int life = 100);
	//Personnage(Personnage const& toCopy);
	
	virtual ~Personnage();
	
	int getLife() const  {return _life;};
	
	
	virtual void introduce() const;
	void getInjured(int deg);
	void getHealed(int life);
	
	void attack(Personnage & ennemy) const;
	void punch(Personnage & ennemy) const;
	
	bool isAlive() const;
	
protected:
	std::string _name;
	int _life;
	Weapon* _weapon;

};

#endif
