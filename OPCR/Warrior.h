#ifndef WARRIOR_H
#define WARRIOR_H

#include <iostream>
#include <string>
#include "Weapon.h"

#include "Personnage.h"

using namespace std;


class Warrior : public Personnage
{

public:
	Warrior();
	Warrior(std::string name);
	virtual ~Warrior();
	
	virtual void introduce() const;
	
	void hitMax(Personnage & ennemy) const;

private:
	int _armor;

};

#endif
