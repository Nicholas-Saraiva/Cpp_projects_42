#include "iter.hpp"
#include <iostream>

template	<typename T>
void	more(T& x)
{
	x++;
}

int main( void ) 
{
	int		arr[] = {1, 2, 3};

	::iter(arr, 3, more);
	for (int i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}

	int		arr2[] = {'a', 'b', 'c'};

	::iter(arr2, 3, more);
	for (int i = 0; i < 3; i++)
	{
		std::cout << (char)arr2[i] << std::endl;
	}
}