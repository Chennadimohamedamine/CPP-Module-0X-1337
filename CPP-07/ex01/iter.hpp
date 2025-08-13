#ifndef ITER_HPP
#define ITER_HPP


#include <iostream>
#include <string>

template <typename T>
void iter(T* arr, int len, void (*fun)(T&)) {
    for (int i = 0; i < len; ++i)
        fun(arr[i]);
}

template <typename T>
void iter(const T* arr, int len, void (*fun)(const T&)) {
    for (int i = 0; i < len; ++i)
        fun(arr[i]);
}

template <typename T>
void print(T x)
{
    std::cout <<  "the value of x: " << x << std::endl;
}
#endif