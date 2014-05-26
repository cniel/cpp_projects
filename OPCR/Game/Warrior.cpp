#include "Warrior.h"

using namespace std;


Warrior::Warrior() : Personnage(), _armor(50)
{

}

Warrior::Warrior(string name) : Personnage(name), _armor(50)
{

}

Warrior::~Warrior()
{

}


void Warrior::introduce() const
{
	Personnage::introduce();
	cout << "My armor is at " << _armor << ".\n\n";
}

void Warrior::hitMax(Personnage & ennemy) const
{
	if(isAlive())
	{
		if(_weapon != NULL)
			ennemy.getInjured(2*_weapon->getStrength());
		else
			this->attack(ennemy); this->attack(ennemy);
	}
}
