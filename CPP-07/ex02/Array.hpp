#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>

class Array
{
private:
    T *arr;
    unsigned int size;

public:
    class OutOfRange : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "the index is out of range";
        }
    };
    Array() : arr(NULL), size(0) {}
    Array(unsigned int n)
    {
        if (n > 0)
        {
            arr = new T[n];
            size = n;
        }
        else
        {
            arr = NULL;
            size = 0;
        }
    }
    Array(const Array &arr)
    {
        *this = arr;
    }
    Array &operator=(Array const &arr)
    {
        if (this != &arr)
        {
            if (arr.size != 0)
            {
                this->arr = new T[arr.size];
                this->size = arr.size;
                for (unsigned int i = 0; i < arr.size; i++)
                    this->arr[i] = arr.arr[i];
            }
            else
            {
                this->arr = NULL;
                this->size = 0;
            }
        }
        return *this;
    }
    T &operator[](unsigned int index)
    {
        if (index >= this->size)
            throw OutOfRange();
        return this->arr[index];
    }
    const T &operator[](unsigned int index) const
    {
        if (index >= this->size)
            throw OutOfRange();
        return this->arr[index];
    }
    unsigned int getSize() const
    {
        return this->size;
    }

    ~Array()
    {
        if (this->arr != NULL)
            delete[] this->arr;
    }
};

#endif