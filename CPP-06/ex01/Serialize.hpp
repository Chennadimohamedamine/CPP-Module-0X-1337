#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include "Data.hpp"

class Serialize
{
    private:
        Serialize();
        Serialize(const Serialize& other);
        Serialize& operator=(const Serialize& other); 
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
#endif