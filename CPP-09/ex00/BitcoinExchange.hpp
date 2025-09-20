#pragma once

#include <iostream>
#include <stdexcept>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

class BitcoinExchange{
    private:
    std::map<std::string, float> data;
    std::string filename;
    public:
        class Errorsfile: public std::exception{
            public:
            const char *what() const throw();
        };
    BitcoinExchange(int ac, char *st);
    BitcoinExchange(const BitcoinExchange &bitcoinExchange);
    BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);
    void StoreData(std::ifstream &file);
    bool ParceInput(std::string key, std::string value);
    void ProcessProgram(std::ifstream &file);
    void startProgram();
    ~BitcoinExchange();
};