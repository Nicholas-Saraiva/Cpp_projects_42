
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

	Fixed&	operator=(const Fixed& other);

	int		getRawBits() const;
	int		toInt(void) const;
	float	toFloat(void) const;
	void	setRawBits(int const raw);


	~Fixed();
};

std::ostream& operator<<(std::ostream& stream, Fixed const& other);