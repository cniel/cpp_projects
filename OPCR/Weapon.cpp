#include "Weapon.h"

using namespace std;


//===================================================
// Weapon : Constructors
//===================================================
Weapon::Weapon() : _name("canif"), _strength(8) 
{

}

Weapon::Weapon(string name, int strength) : _name(name), _strength(strength)
{

}

Weapon::Weapon(Weapon const& toCopy) : _name(toCopy._name), _strength(toCopy._strength)
{

}
