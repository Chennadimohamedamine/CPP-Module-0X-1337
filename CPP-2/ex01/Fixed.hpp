#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int var);
    Fixed(const float var);
    Fixed(const Fixed &fixed);
    Fixed &operator=(Fixed const &fixed);
    int getRawBits(void) const;
    float toFloat(void) const;
    int toInt(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};
std::ostream &operator<<(std::ostream &out,const Fixed &fixed);