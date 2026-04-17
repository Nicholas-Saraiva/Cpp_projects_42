#pragma once
#include <string>
#include <stdint.h>

typedef	struct Data_s
{
	std::string	secret;
}	Data;


class Serialize
{
private:
	Serialize();
	Serialize(const Serialize& other);
	Serialize&	operator=(const Serialize& other);
	~Serialize();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};