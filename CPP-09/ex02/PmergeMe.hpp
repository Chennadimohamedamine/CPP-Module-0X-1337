#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <deque>
#include <set>
#include <ctime>

class PmergeMe
{
    private:
        std::vector<int> dataVector;
        std::deque<int>  dataDeque;
        unsigned int size;
        clock_t startTime;
        clock_t endTime;
    public:
        PmergeMe(int ac, char **av);
        class InvalidInputException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        std::vector<size_t> Jacobsthal(int n);
        template <typename T>
        void binarySearch(T &arr, int value);
        template <typename T>
        void MergeInsertionSort(T &container);
        void startProcessing();
        template <typename T>
        void Display(T &data) const;
        bool hasDuplicates() const;
        ~PmergeMe();
};

