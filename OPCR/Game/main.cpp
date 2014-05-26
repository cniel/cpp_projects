#include <iostream>
#include <string>

#include "Warrior.h"
#include "Wizard.h"

#include "StringServices.h"

using namespace std;


void present(Personnage const& p)
{
	p.introduce();
}

int main(int argc, char** argv)
{
	StringServices::encadre("Let the Game BEGIN !");
	
	Personnage villageois();
	Warrior goliath("Goliath");
	Wizard merlin;

	goliath.hitMax(merlin);
	merlin.fireBall(goliath);

	goliath.introduce();
	merlin.introduce();

	present(merlin);

	StringServices::encadre("END of the Game.");

	return 0;
}
