
class Fixed
{
private:
	int	_fixedPoint;
	const static int	_bits = 8;
public:
	Fixed();

	Fixed(const Fixed& other);

	Fixed&	operator=(const Fixed& other);

	int		getRawBits() const;
	void	setRawBits(int const raw);
	~Fixed();
};