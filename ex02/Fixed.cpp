#include "Fixed.hpp"
#include <bitset>

int Fixed::getRawBits( void ) const
{
	return _fp_value;
}

void Fixed::setRawBits( int const raw )
{
	_fp_value = raw;
} 

float Fixed::toFloat() const
{
	float	 res;
	int		shift;

	shift = pow(2, _fr_bits);
	res = float(_fp_value) / float(shift);
	return res;
}

int Fixed::toInt() const
{
	int	res;

	res = _fp_value >> _fr_bits;
	return res;
}

Fixed& Fixed::min( Fixed &a, Fixed &b )
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a < b)
		return a;
	return b;
}
Fixed& Fixed::max( Fixed &a, Fixed &b )
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a > b)
		return a;
	return b;
}

Fixed::Fixed()
{
	_fp_value = 0;
}

Fixed::Fixed(const int num)
{
	_fp_value = num << _fr_bits;
}

Fixed::Fixed(const float flt)
{
	int shift;

	shift = pow(2, _fr_bits);
	_fp_value = roundf(flt * shift);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

bool Fixed::operator > (const Fixed &cmp) const
{
	return (getRawBits() > cmp.getRawBits());
}

bool Fixed::operator >= (const Fixed &cmp) const
{
	return (getRawBits() >= cmp.getRawBits());
}

bool Fixed::operator < (const Fixed &cmp) const
{
	return (getRawBits() < cmp.getRawBits());
}

bool Fixed::operator <= (const Fixed &cmp) const
{
	return (getRawBits() <= cmp.getRawBits());
}

bool Fixed::operator == (const Fixed &cmp) const
{
	return (getRawBits() == cmp.getRawBits());
}

bool Fixed::operator != (const Fixed &cmp) const
{
	return (getRawBits() != cmp.getRawBits());
}

Fixed& Fixed::operator = (const Fixed &fixed)
{
	if (this != &fixed)
		this->_fp_value = fixed.getRawBits();
	return *this;	
}

Fixed Fixed::operator + (const Fixed &fixed) const
{
	Fixed result;

	result.setRawBits(getRawBits() + fixed.getRawBits());
	return result;	
}


Fixed Fixed::operator - (const Fixed &fixed) const
{
	Fixed result;

	result.setRawBits(getRawBits() - fixed.getRawBits());
	return result;	
}


Fixed Fixed::operator * (const Fixed &fixed) const
{
	Fixed result(toFloat() * fixed.toFloat());

	return result;	
}


Fixed Fixed::operator / (const Fixed &fixed) const
{
	Fixed result(toFloat() / fixed.toFloat());

	return result;	
}

Fixed& Fixed::operator ++()
{
	++_fp_value;
	return *this;
}

Fixed Fixed::operator ++(int)
{
	Fixed old(*this);

	++_fp_value;
	return old;
}
Fixed& Fixed::operator --()
{
	--_fp_value;
	return *this;
}

Fixed Fixed::operator --(int)
{
	Fixed old(*this);

	--_fp_value;
	return old;
}
std::ostream& operator << (std::ostream& os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}