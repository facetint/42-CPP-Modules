#pragma once

#include <iostream>
#include <stdint.h>

struct Data;

class Serialization
{
    private:
        Serialization();
        Serialization(Serialization const &src);
        ~Serialization();
        Serialization & operator=(Serialization const &other);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};
