#ifndef WIZARD_H
#define WIZARD_H

#include <iostream>
#include <string>
#include "Weapon.h"

#include "Personnage.h"

using namespace std;


class Wizard : public Personnage
{

public:
	Wizard();
	virtual ~Wizard();
	
	virtual void introduce() const;
	
	void fireBall(Personnage & ennemy);
	void heal(Personnage & ally);
	void resurect(Personnage & ally);
	
	
protected:
	int _mana;

};

#endif
