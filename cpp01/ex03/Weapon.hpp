#pragma once

#include <string>

class Weapon
{
private:
	std::string	type;
public:
	Weapon();
	Weapon(std::string name);

	const std::string	getType();
	void				setType(std::string weapon);

	~Weapon();
};