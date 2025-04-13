#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int value;
    static const int _fractionalBits;

public:
    Fixed();
    Fixed(const int var);
    Fixed(const float var);
    Fixed(const Fixed &fixed);
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static Fixed  const &min(Fixed const &a, Fixed const &b);
    static Fixed  const &max(Fixed const &a, Fixed const &b);


    /* ========== operator ================ */
    Fixed &operator=(Fixed const &fixed);
    Fixed operator+(Fixed const &fixed) const;
    Fixed operator-(Fixed const &fixed) const;
    Fixed operator*(Fixed const &fixed) const;
    Fixed operator/(Fixed const &fixed) const;

    /* ========== comparision  operator ================ */
    bool operator>(Fixed const &fixed) const;
    bool operator<(Fixed const &fixed) const;
    bool operator>=(Fixed const &fixed) const;
    bool operator<=(Fixed const &fixed) const;
    bool operator==(Fixed const &fixed) const;
    bool operator!=(Fixed const &fixed) const;
    
    /* ========== increment decrement operator ================ */
    Fixed &operator++(void);
    Fixed operator++(int);
    Fixed &operator--(void);
    Fixed operator--(int);


    int getRawBits(void) const;
    float toFloat(void) const;
    int toInt(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};
std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
