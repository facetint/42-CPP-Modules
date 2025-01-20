#pragma once

#include <iostream>
#include <stdint.h>

struct Data;

class Serializer
{
    private:
        Serializer();
        Serializer(Serializer const &src);
        ~Serializer();
        Serializer & operator=(Serializer const &other);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};
