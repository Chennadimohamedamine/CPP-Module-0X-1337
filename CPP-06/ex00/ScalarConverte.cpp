#include "ScalarConverte.hpp"

void ScalarConverter::convert(const std::string &st)
{
    int define = defineType(st);
    if (define != -1)
    {
        if (define == 0)
            define = convertTypeOne(st);
        else if (define == 1)
            define = convertTypeTow(st);
        else if (define == 2)
            define = convertTypeTree(st);
        else if (define == 3)
            std::cout << "char: impossible\n"
                      << "int: impossible\n"
                      << "float: " << st << "f\n"
                      << "double: " << st << std::endl;
        else if (define == 4)
            std::cout << "char: impossible\n"
                      << "int: impossible\n"
                      << "float: " << st << "\n"
                      << "double: " << st.substr(0, st.length() - 1) << std::endl;
    }
    if (define == -1)
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
}
