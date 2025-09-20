#include "BitcoinExchange.hpp"

const char* BitcoinExchange::Errorsfile::what() const throw(){
    return " could not open file";
}

BitcoinExchange::BitcoinExchange(int ac, char *st){
    if (ac == 1)
        throw Errorsfile();
    filename = st;
    startProgram();
}
void BitcoinExchange::StoreData(std::ifstream &file)
{
    std::string line, key, value;
    while (std::getline(file, line))
    {
        key = line.substr(0, 10);
        value = line.substr(11, line.size());
        data[key] = std::atof(value.c_str()); 
    }
}
bool  BitcoinExchange::ParceInput(std::string key, std::string value)
{
    std::stringstream ss(key);
    std::string token;
    int c = 0;
    int year, month, day;
    while (std::getline(ss, token, '-')){
        if (c == 0)
            year = std::atoi(token.c_str());
        else if(c == 1)
        {
            month = std::atoi(token.c_str());
            if (month < 1 || month > 12)
            {
                std::cout << "Error: bad input => " << key << std::endl;
                return false;
            }
        }
        else if (c == 2)
        {

            day = std::atoi(token.c_str());
            if (day < 1 || day > 31)
            {
                std::cout << "Error: bad input => " << key << std::endl;
                return false;
            }
        }
        c++;
    }
    float fvalue = std::atof(value.c_str());
    if (fvalue < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (fvalue > 1000)
    {
        std::cout << "Error: too large a number."<< std::endl;
        return false;
    }
    return true;
}
void BitcoinExchange::ProcessProgram(std::ifstream &file)
{
    std::string line, key, slash,value;
    float finput, fdata, fresult;
    int i = 0, hascontent = 0;
    while (std::getline(file, line))
    {
        hascontent = 1;
        if (i == 0)
        {
            if (line != "date | value")
            {
                std::cout << "Error: shoude be start with date | value" << std::endl;
                return ;
            }
            i++;
            continue;
        }
        if (line.empty())
        {
            std::cout << "Error: empty line" << std::endl;
            continue;
        }
        std::stringstream ss(line);
        ss >> key >> slash >> value;
        if (slash != "|")
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (ParceInput(key, value))
        {
            if (data.find(key) != data.end())
            {
                fdata = data[key];
                finput = std::atof(value.c_str());
                fresult = fdata * finput;
                std::cout << key << " => " << value << " = " <<  fresult<< std::endl;
            }else
            {
                std::map<std::string, float>::iterator it = data.lower_bound(key);
                if (it == data.begin())
                {
                    std::cout << "Error: no data available before " << key << std::endl;
                    continue ;
                }
                --it;
                fdata = it->second;
                finput = std::atof(value.c_str());
                fresult = fdata * finput;
                std::cout << key << " => " << value << " = " <<  fresult<< std::endl;
            }
        }
    }
    if (!hascontent)
        std::cout << "Error: empty file" << std::endl;
}
void BitcoinExchange::startProgram()
{
    std::ifstream dt("data.csv");
    if (!dt.is_open())
        throw Errorsfile();
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        dt.close();
        throw Errorsfile();
    }
    StoreData(dt);
    ProcessProgram(file);
    dt.close();
    file.close();
}

BitcoinExchange::~BitcoinExchange() {
}