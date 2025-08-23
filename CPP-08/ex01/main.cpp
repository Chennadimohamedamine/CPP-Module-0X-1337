#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(2);
        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        Span s = Span(5);
        std::vector<int> b;
        b.push_back(6);
        b.push_back(855);
        b.push_back(85555);
        b.push_back(632);
        b.push_back(41);
        s.addNumber(0);
        s.addNumber(85);
        s.addNumber(5);
        s.addNumbers(b.begin(), b.end());
        std::cout << s.shortestSpan() << std::endl;
        std::cout << s.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << '\n';
    }
    
    return 0;
}