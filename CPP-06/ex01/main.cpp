#include "Serialize.hpp"

int main() {
    int value = 42;
    Data myData = {"Example", value};

    uintptr_t serialized = Serialize::serialize(&myData);
    std::cout << "Serialized pointer: " << serialized << std::endl;

    Data* deserializedPtr = Serialize::deserialize(serialized);
    std::cout << "Deserialized value: " << deserializedPtr->value << std::endl;
    std::cout << "Deserialized name: " << deserializedPtr->name << std::endl;

    return 0;
}