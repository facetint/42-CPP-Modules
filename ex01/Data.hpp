#pragma once

#include <iostream>
#include <stdint.h>

struct Data
{
    private:
        Data();
        uintptr_t _value;
    public:
        Data(uintptr_t value);
        Data(Data const &src);
        ~Data();
        Data & operator=(Data const &other);
        uintptr_t getValue() const;
        void setValue(uintptr_t value);

};
