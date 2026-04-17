#include "Serialize.hpp"
#include <iostream>

int main()
{
	Data	a = {.secret = "i dont have one!"};
	uintptr_t	ptr = Serialize::serialize(&a);

	std::cout << ptr << std::endl;
	std::cout << Serialize::deserialize(ptr)->secret << std::endl;

}