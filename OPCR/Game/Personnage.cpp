#include "Personnage.h"


using namespace std;

//===================================================
// Personnage : Constructors
//===================================================
Personnage::Personnage() : _name("Personnage"), _life(100)
{
	_weapon = new Weapon();
}

Personnage::Personnage(string name) : _name(name), _life(100)
{
	_weapon = new Weapon();
}

Personnage::Personnage(string name, int life) : _name(name), _life(life)
{
	_weapon = new Weapon();
}

/*
Personnage::Personnage(string name, string weapon, int strength, int life) : _name(name), _life(life)
{
	_weapon = new Weapon(weapon, strength);
}

Personnage::Personnage(Personnage const& toCopy) : _name(toCopy._name), _life(toCopy._life)
{
	_weapon = new Weapon(*(toCopy._weapon));
}
*/

//===================================================
// Personnage : Destructor
//===================================================
Personnage::~Personnage()
{
	cout << _name << " is dead.\n";
	delete _weapon;
}


//===================================================
// Personnage : introduce
//===================================================
void Personnage::introduce() const
{
	cout << "My name is " << _name << ". I'm ";
	if(_life > 75)
		cout << "very fine !";
	else if(_life > 50)
		cout << "not too bad.";
	else if(_life > 25)
		cout << "injured...";
	else cout << "ailing !";
	
	cout << " (" << _life << "pv)\n"; 
}

//===================================================
// Personnage : getInjured
//===================================================
void Personnage::getInjured(int deg)
{
	_life -= deg;
	if(_life < 0)
		_life = 0;
}

//===================================================
// Personnage : getHealed
//===================================================
void Personnage::getHealed(int life)
{
	_life += life;
}

//===================================================
// Personnage : punch
//===================================================
void Personnage::punch(Personnage & ennemy) const
{
	if(isAlive())
		ennemy.getInjured(5);
}

//===================================================
// Personnage : attack
//===================================================
void Personnage::attack(Personnage & ennemy) const
{
	if(isAlive())
	{
		if(_weapon)
			ennemy.getInjured(_weapon->getStrength());
		else
			this->punch(ennemy);
	}
}

//===================================================
// Personnage : isAlive
//===================================================
bool Personnage::isAlive() const
{
	return (_life > 0);
}
