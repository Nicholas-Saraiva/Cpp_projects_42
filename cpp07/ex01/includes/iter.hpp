#pragma once

template	<typename T>
void	iter(T arr[], const int size, void (*f)(T&))
{
	for (int i = 0; i < size; i++)
	{
		(*f)((arr)[i]);
	}
}