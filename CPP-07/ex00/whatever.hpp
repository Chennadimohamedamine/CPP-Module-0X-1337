#ifndef WEATHER_HPP
#define WEATHER_HPP


#include <iostream>
#include <string>

template <typename T>
void swap(T &x, T &y){
    T s = x;
    x = y;
    y = s;

}
template <typename T>
T max(T x, T y){
   return  x > y ? x : y; 
}
template <typename T>
T min(T x, T y){
   return  x > y ? y : x;
}

#endif