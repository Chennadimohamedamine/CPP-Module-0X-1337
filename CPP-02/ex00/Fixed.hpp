#pragma once

#include <iostream>


class Fixed {
    private:
        int _value;
        static const int _fractionalBits;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        void operator=(Fixed &fixed);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        ~Fixed();

};