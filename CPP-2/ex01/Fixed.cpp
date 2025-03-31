#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}
Fixed::Fixed(const Fixed &fixed) {
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}

Fixed::Fixed(const int var)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = var << _fractionalBits;
}

Fixed::Fixed(const float var)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = round(var * (1 << _fractionalBits));
}
Fixed &Fixed::operator=(Fixed const &fixed) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->value = fixed.value;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}


float Fixed::toFloat( void ) const {
    return static_cast<float>(value) / (1 << _fractionalBits);
}
int Fixed::toInt( void ) const {
    return value >> _fractionalBits;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    value = raw;
}
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
