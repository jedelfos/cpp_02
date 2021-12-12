#ifndef __FIXED__H__
#define __FIXED__H__
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_fp_value;
	static const int _fr_bits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed & operator = (const Fixed &fixed);
	Fixed operator + (const Fixed &fixed) const;
	Fixed operator - (const Fixed &fixed) const;
	Fixed operator * (const Fixed &fixed) const;
	Fixed operator / (const Fixed &fixed) const;
	bool operator > (const Fixed &cmp) const;
	bool operator >= (const Fixed &cmp) const;
	bool operator < (const Fixed &cmp) const;
	bool operator <= (const Fixed &cmp) const;
	bool operator == (const Fixed &cmp) const;
	bool operator != (const Fixed &cmp) const;
	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);

	int getRawBits( void ) const;
	void setRawBits( int const raw );

	float 	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min( Fixed &a, Fixed &b );
	static const Fixed	&min( const Fixed &a, const Fixed &b );
	static Fixed		&max( Fixed &a, Fixed &b );
	static const Fixed	&max( const Fixed &a, const Fixed &b );
};

std::ostream& operator<< (std::ostream& os, const Fixed &fixed);

#endif