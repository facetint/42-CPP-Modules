#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    try {
        Data *ptr = new Data(10);

        std::cout << "Default address: " << ptr << std::endl;
        std::cout << std::endl;

        uintptr_t a = Serializer::serialize(ptr);
        std::cout << "Serialized value: " << a << std::endl;
        std::cout  << std::endl;

        ptr = Serializer::deserialize(a);
        std::cout << "Deserialized address: " << ptr << std::endl;
        std::cout << std::endl;

        delete ptr;
    } catch (std::exception &e) {
        std::cerr << "Error:  " << e.what() << std::endl;
    }

    return 0;
}
