#ifndef SALARCONVERTE_HPP
#define SALARCONVERTE_HPP

#include "./convert.hpp"

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
    public:
        static void convert(const std::string &st);
};

#endif