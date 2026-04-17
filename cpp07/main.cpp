#include "whatever.hpp"
#include <iostream>

void	swap(void** a, void** b)
{
	void *c = *a;

	a = b;
	b = &c;
}

int main()
{
	int	a = 22;
	int b = 99;

	std::cout << "AFTER" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;

	swap(reinterpret_cast<void**>(&a), reinterpret_cast<void**>(&b));

	std::cout << "BEFORE" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
}