#ifndef __FIXED__H__
#define __FIXED__H__
#include <iostream>

class Fixed
{
private:
	int	_fp_value;
	static const int _fr_bits = 8;
public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);

	int getRawBits( void ) const;
	void setRawBits( int const raw ); 
};

#endif