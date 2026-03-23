#include <iostream>
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
		
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int fixedPoint)
{
	_fixedPoint = fixedPoint << _bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedPoint)
{
	_fixedPoint = roundf(fixedPoint * (1 << _bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits() const
{
	return this->_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(getRawBits()) / (1 << _bits));
};

int	Fixed::toInt(void) const
{
	return (static_cast<int>(getRawBits() >> _bits));
};


std::ostream &operator<<(std::ostream &stream, Fixed const &other)
{
	stream << other.toFloat();
	return (stream);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;

}
