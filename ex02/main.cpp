#include <iostream>
#include "Fixed.hpp"
int main( void ) {
	Fixed a(10);
	Fixed c(10);
	Fixed b(42.42f);

	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "a < b :" << (a < b) << std::endl;
	std::cout << "a <= c :" << (a <= c) << std::endl;
	std::cout << "a >= c :" << (a >= c) << std::endl;
	std::cout << "a > b :" << (a > b) << std::endl;
	std::cout << "a == c :" << (a == c) << std::endl;
	std::cout << "a != c :" << (a != c) << std::endl;
	std::cout << "a + b :" << (a + b) << std::endl;
	std::cout << "a - b :" << (a - b) << std::endl;
	std::cout << "a * b :" << (a * b) << std::endl;
	std::cout << "a / b :" << (a / b) << std::endl;
	std::cout << "++a :" << (++a) << std::endl;
	std::cout << "++b :" << (++b) << std::endl;
	std::cout << "a++ :" << (a++) << std::endl;
	std::cout << "b++ :" << (b++) << std::endl;
	std::cout << "a :" << a << std::endl;
	std::cout << "b :" << b << std::endl;
	std::cout << "c :" << c << std::endl;
	std::cout << "Fixed::max(a,b) :" << Fixed::max( a, b ) << std::endl;
	std::cout << "Fixed::min(a,b) :" << Fixed::min( a, b ) << std::endl;
	std::cout << "Fixed(-1) / Fixed(5) :" << Fixed(-1) / Fixed(5) << "\n\n";

	std::cout << "main sujet\n";
	Fixed d;
	Fixed const e( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << d << std::endl;
	std::cout << ++d << std::endl;
	std::cout << d << std::endl;
	std::cout << d++ << std::endl;
	std::cout << d << std::endl;
	std::cout << e << std::endl;
	std::cout << Fixed::max( d, e ) << std::endl;


	return 0;
}
