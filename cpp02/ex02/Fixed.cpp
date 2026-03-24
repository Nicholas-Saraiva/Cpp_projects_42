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

bool Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return !(*this == other);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	return Fixed(this->getRawBits() + other.getRawBits());
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	return Fixed(this->getRawBits() - other.getRawBits());
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long	tmp = (static_cast<long long>(this->getRawBits()) * \
		static_cast<long long>(other.getRawBits())) >> _bits;

	result.setRawBits(tmp);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long long	n = static_cast<long long>(this->getRawBits()) << _bits;

	if (other.getRawBits() == 0)
		return (Fixed(0));
	result.setRawBits(static_cast<int>(n / other.getRawBits()));
	return result;
}

Fixed&	Fixed::operator++()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;

	this->setRawBits(this->getRawBits() + 1);
	return temp;
}

Fixed&	Fixed::operator--()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;

	this->setRawBits(this->getRawBits() - 1);
	return temp;
}

Fixed&	Fixed::min(Fixed& num1, Fixed& num2)
{
	return ((num1 < num2) ? num1 : num2);
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2)
{
	return ((num1 < num2) ? num1 : num2);
}

Fixed&	Fixed::max(Fixed& num1, Fixed& num2)
{
	return ((num1 > num2) ? num1 : num2);
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2)
{
	return ((num1 > num2) ? num1 : num2);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &other)
{
	stream << other.toFloat();
	return (stream);
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
