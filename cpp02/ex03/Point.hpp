#pragma once

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;

public:
	Point();
	Point(const Fixed& fp1, const Fixed& fp2);
	Point(const Point& other);

	Point&	operator=(const Point& other);
	Point	operator+(const Point& other) const;
	Point	operator-(const Point& other) const;

	Fixed	getX() const;
	Fixed	getY() const;
	~Point();
};
