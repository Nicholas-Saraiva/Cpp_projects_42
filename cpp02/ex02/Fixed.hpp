#include <ostream>

class Fixed
{
private:
	int	_fixedPoint;
	const static int	_bits = 8;
public:
	Fixed();

	Fixed(const Fixed& other);
	Fixed(const int fixedPoint);
	Fixed(const float fixedPoint);

	Fixed&			operator=(const Fixed& other);
	bool			operator<(const Fixed& other) const;
	bool			operator>(const Fixed& other) const;
	bool			operator>=(const Fixed& other) const;
	bool			operator<=(const Fixed& other) const;
	bool			operator==(const Fixed& other) const;
	bool			operator!=(const Fixed& other) const;
	Fixed			operator+(const Fixed& other) const;
	Fixed			operator-(const Fixed& other) const;
	Fixed			operator*(const Fixed& other) const;
	Fixed			operator/(const Fixed& other) const;
	Fixed&			operator++();
	Fixed			operator++(int);
	Fixed&			operator--();
	Fixed			operator--(int);

	int				getRawBits() const;
	int				toInt(void) const;
	float			toFloat(void) const;
	void			setRawBits(int const raw);

	static Fixed&	min(Fixed& num1, Fixed& num2);
	static const	Fixed&	min(const Fixed& num1, const Fixed& num2);
	static Fixed&	max(Fixed& num1, Fixed& num2);
	static const	Fixed&	max(const Fixed& num1, const Fixed& num2);

	~Fixed();
};

std::ostream& operator<<(std::ostream& stream, Fixed const& other);