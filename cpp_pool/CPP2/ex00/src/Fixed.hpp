#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
private:
	int			fixedNumber;
	static const int	sizeOfFractionedBits;
public:
	Fixed();
	Fixed(Fixed &newNumber);
	~Fixed();
	
	Fixed		&operator=( const Fixed &other );
	int		getRawBits( void ) const;
	void		setRawBits( int const raw );
};

#endif
