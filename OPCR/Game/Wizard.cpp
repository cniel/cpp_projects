#include "Wizard.h"


using namespace std;


Wizard::Wizard() : Personnage("Wizard", 80), _mana(100)
{

}

Wizard::~Wizard()
{

}

void Wizard::introduce() const
{
	Personnage::introduce();
	cout << "My mana is at " << _mana << ".\n\n";
}


void Wizard::fireBall(Personnage & ennemy)
{
	ennemy.getInjured(45);
	_mana -= 20;
}


void Wizard::heal(Personnage & ally)
{
	if(!ally.isAlive())
	{
		ally.getHealed(30);
		_mana -= 20;
	}
}

void Wizard::resurect(Personnage & ally)
{
	if(!ally.isAlive())
	{
		ally.getHealed(30);
		_mana -= 30;
	}
}
