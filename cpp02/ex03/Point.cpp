#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &fp1, const Fixed &fp2) : x(fp1), y(fp2)
{}

Point::Point(const Point &other) : x(other.getX()), y(other.getY())
{}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return *this;
}

Point Point::operator+(const Point &other) const
{
	return Point(this->getX() + other.getX(), this->getY() + other.getY());
}

Point Point::operator-(const Point &other) const
{
	return Point(this->getX() - other.getX(), this->getY() - other.getY());
}

Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

Point::~Point(){}
