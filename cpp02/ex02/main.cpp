#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "--- Subject Tests ---" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\n--- Arithmetic & Precision Tests ---" << std::endl;
    Fixed c(10.10f);
    Fixed d(2);
    Fixed result = c / d;

    std::cout << "c: " << c << " (Raw: " << c.getRawBits() << ")" << std::endl;
    std::cout << "d: " << d << " (Raw: " << d.getRawBits() << ")" << std::endl;
    std::cout << "c / d = " << result << " (Raw: " << result.getRawBits() << ")" << std::endl;
    
    Fixed expected(5.05f);
    std::cout << "Is result == 5.05f? " << (result == expected ? "Yes" : "No") << std::endl;

    std::cout << "\n--- Comparison Tests ---" << std::endl;
    std::cout << "b > a : " << (b > a) << std::endl;
    std::cout << "b < a : " << (b < a) << std::endl;
    std::cout << "b == b: " << (b == b) << std::endl;
    std::cout << "b != a: " << (b != a) << std::endl;
    std::cout << "b == a: " << (b == a) << std::endl;


    std::cout << "\n--- Min/Max Const Tests ---" << std::endl;
    const Fixed e(10);
    const Fixed f(20);
    std::cout << "Min of const 10 and 20: " << Fixed::min(e, f) << std::endl;
    std::cout << "Max of const 10 and 20: " << Fixed::max(e, f) << std::endl;

    return 0;
}