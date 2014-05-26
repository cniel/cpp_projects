#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

class Weapon
{
public:
	Weapon();
	Weapon(std::string name, int strength);
	Weapon(Weapon const& toCopy);
	
	int getStrength() const {return _strength;};

private:
	std::string _name;
	int _strength;

};

#endif
