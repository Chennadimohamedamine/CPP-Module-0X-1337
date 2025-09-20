#include "PmergeMe.hpp"

const char *PmergeMe::InvalidInputException::what() const throw()
{
    return "Error";
}

PmergeMe::PmergeMe(int ac, char **av)
{
    if (ac < 2)
        throw InvalidInputException();
    for (int i = 1; i < ac; i++)
    {
        std::string str(av[i]);
        if (!str.empty())
        {
            if ((str.find_first_not_of("+0123456789") != std::string::npos) ||
                (str.find_first_of("+") != std::string::npos && str.find_first_of("+") != 0) || (str.length() > 10 || (str.length() == 10 && str > "2147483647")))
                throw InvalidInputException();
            std::istringstream iss(str);
            int num;
            while (iss >> num)
            {
                if (hasDuplicates())
                    throw InvalidInputException();
                dataVector.push_back(num);
                dataDeque.push_back(num);
            }
        }
    }
    size = dataVector.size();
}

bool PmergeMe::hasDuplicates() const
{
    std::set<int> uniqueElements(dataVector.begin(), dataVector.end());
    return uniqueElements.size() < dataVector.size();
}
template <typename T>
void PmergeMe::Display(T &data) const
{
    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void PmergeMe::binarySearch(T &arr, int value)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    arr.insert(arr.begin() + left, value);
}
template <typename T>
void PmergeMe::MergeInsertionSort(T &arr)
{
    int unpairedElement = -1;
    T mainChain, pendChain;
    if (arr.size() < 2)
        return;
    if (arr.size() % 2 != 0)
    {
        unpairedElement = arr.back();
        arr.pop_back();
    }
    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] < arr[i + 1])
            std::swap(arr[i], arr[i + 1]);
        mainChain.push_back(arr[i]);
        pendChain.push_back(arr[i + 1]);
    }
    arr.clear();
    arr = mainChain;
    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
            {
                std::swap(arr[i], arr[j]);
                std::swap(pendChain[i], pendChain[j]);
            }
        }
    }
    arr.insert(arr.begin(), pendChain[0]);
    pendChain.erase(pendChain.begin());
    std::vector<size_t> jacobsthal = Jacobsthal(pendChain.size());
    for (size_t i = 1; i < jacobsthal.size(); i++)
    {
        if (jacobsthal[i] - 1 < pendChain.size())
            binarySearch(arr, pendChain[jacobsthal[i] - 1]);
    }
    if (unpairedElement != -1)
        binarySearch(arr, unpairedElement);
}
std::vector<size_t> PmergeMe::Jacobsthal(int n)
{
    std::vector<size_t> seq;
    std::vector<size_t> result;

    seq.push_back(0);
    seq.push_back(1);
    while ((int)seq.size() < n + 2)
    {
        int next = seq[seq.size() - 1] + 2 * seq[seq.size() - 2];
        seq.push_back(next);
    }
    seq.erase(seq.begin() + 2);
    result.push_back(0);
    result.push_back(1);
    for (size_t i = 1; i < seq.size(); i++)
    {
        if (i + 1 < seq.size())
        {
            int next = seq[i + 1], current = seq[i], count = 0;
            result.push_back(next);
            while (++current < next)
                count++;
            while (count-- > 0)
                result.push_back(--current);

        }
    }
    return result;
}
void PmergeMe::startProcessing()
{
    std::cout << "Before: ";
    Display(dataVector);
    startTime = clock();
    MergeInsertionSort(dataVector);
    endTime = clock();
    std::cout << "after : "; 
    Display(dataVector);
    double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << size << " elements with vector: "
              << elapsedTime << " seconds" << std::endl;
    startTime = clock();
    MergeInsertionSort(dataDeque);
    endTime = clock();
    elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << size << " elements with deque : "
              << elapsedTime << " seconds" << std::endl;
}

PmergeMe::~PmergeMe(){}
