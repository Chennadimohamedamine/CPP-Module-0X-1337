#include "Span.hpp"


const char * Span::SpanAlreadyFull::what() const throw()
{
    return "Cannot add number: the Span is already full.";
}
const char * Span::NotEnoughElementsException::what() const throw()
{
    return "Cannot compute span: need at least two elements.";
}
Span::Span(unsigned int n):N(n){
    // std::cout << "Span constructor is called" << std::endl;
};
Span::Span(const Span &s){
    // std::cout << "Span copy constructor is called"<< std::endl;
    *this = s;
};

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
    {
        size_t count = std::distance(begin, end);
        if (count < N)
            v.insert(v.end(), begin ,end);
        else
            throw SpanAlreadyFull();
}
void Span::addNumber(unsigned int n){
    if (v.size() < N)
        v.push_back(n);
    else
        throw SpanAlreadyFull();
}

unsigned int Span::shortestSpan(){
    if (v.size() <= 1)
        throw NotEnoughElementsException() ;
    std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());
    unsigned int min = 4294967295;
    for (size_t i = 0; i < tmp.size() - 1; i++)
    {
        unsigned int d = tmp[i + 1] - tmp[i];
        if (d < min)
            min = d;
    }
    return min;
}
unsigned int Span::longestSpan(){
    if (v.size() <= 1)
        throw NotEnoughElementsException() ;
    std::vector<int> tmp = v;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[0];
    int max = tmp[tmp.size() - 1];
    return max - min;
}

Span& Span::operator=(const Span &s){
    std::cout << "Span operator= is called" << std::endl;
    if (this != &s) {
        this->N = s.N;
        this->v = s.v;
    }
    return *this;
};
Span::~Span(){
    // std::cout << "span destarctur is called " << std::endl;
};