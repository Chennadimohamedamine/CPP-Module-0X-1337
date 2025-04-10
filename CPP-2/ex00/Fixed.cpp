#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed():_value(0){
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    this->_value =  fixed.getRawBits();
}

void Fixed::operator=(Fixed &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = fixed.getRawBits();
}


int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
