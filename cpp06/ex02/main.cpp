#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base*	generate(void)
{
	static	int	isSeed = 0;

	if (isSeed == 0)
	{
		srand(time(0));
		isSeed = 1;
	}
	int	randm = rand() % 3;
	if (randm == 0)
		return (new A);
	else if (randm == 1)
		return (new B);
	return (new C);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "'A'" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "'B'" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "'C'" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "'A'" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "'B'" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "'C'" << std::endl;
	}
	catch(const std::exception& e){}
}

int main()
{
	Base* a = generate();

	identify(a);
	identify(*a);
	delete a;
}