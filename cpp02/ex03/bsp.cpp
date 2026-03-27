#include "Point.hpp"
#include <iostream>

Fixed	cross(const Point a, const Point b)
{
	return (a.getX() * b.getY() - a.getY() * b.getX());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1 = cross(b - a, point - a);
	Fixed	d2 = cross(c - b, point - b);
	Fixed	d3 = cross(a - c, point - c);

	bool	neg =(d1 < 0) || (d2 < 0) || (d3 < 0);
	bool	pos =(d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(neg && pos);
}