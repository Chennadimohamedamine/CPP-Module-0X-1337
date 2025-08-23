#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span{
    private:
        unsigned int N;
        std::vector<int> v;
    public:
    class SpanAlreadyFull : public std::exception{
            public:
             const char *what() const throw();
    };
    class NotEnoughElementsException : public std::exception{
            public:
             const char *what() const throw();
    };
    Span(unsigned int n);
    Span(const Span &s);
    void addNumber(unsigned int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    Span &operator=(const Span &s);
    ~Span();
};


#endif