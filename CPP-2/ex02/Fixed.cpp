#include "Fixed.hpp"

Fixed const  &Fixed::max(Fixed const &a, Fixed const &b){
    return a > b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

Fixed const  &Fixed::min(Fixed const &a, Fixed const &b) {
    return a < b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

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


/* ============ operator ================== */

Fixed Fixed::operator+(Fixed const &fixed) const{
    Fixed result;
    result.setRawBits(this->getRawBits() + fixed.getRawBits());
    return result;
}

Fixed Fixed::operator-(Fixed const &fixed) const{
    Fixed result;
    result.setRawBits(this->getRawBits() - fixed.getRawBits());
    return result;
}

Fixed Fixed::operator*(Fixed const &fixed) const{
    Fixed result;
    result.setRawBits((this->getRawBits() * fixed.getRawBits()) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(Fixed const &fixed) const{
    Fixed result;
    result.setRawBits((this->getRawBits() << _fractionalBits) / fixed.getRawBits());
    return result;
}


/* ============ comparision operator ================== */

bool Fixed::operator>(Fixed const &fixed) const {
    return this->getRawBits() > fixed.getRawBits();
}

bool Fixed::operator<(Fixed const &fixed) const {
    return this->getRawBits() < fixed.getRawBits();
}

bool Fixed::operator>=(Fixed const &fixed) const {
    return this->getRawBits() >= fixed.getRawBits();
}

bool Fixed::operator<=(Fixed const &fixed) const {
    return this->getRawBits() <= fixed.getRawBits();
}

bool Fixed::operator==(Fixed const &fixed) const {
    return this->getRawBits() == fixed.getRawBits();
}

bool Fixed::operator!=(Fixed const &fixed) const {
    return this->getRawBits() != fixed.getRawBits();
}


/* ============ operator increment and decremnt ================== */

Fixed &Fixed::operator++(void)  {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp = *this;
    this->value++;
    return temp;
}

Fixed &Fixed::operator--(void){
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp = *this;
    this->value--;
    return temp;
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
