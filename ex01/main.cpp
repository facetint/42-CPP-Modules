#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

# define MAX_ANIMALS 10

int main() {
    try {
        if (MAX_ANIMALS < 2 || MAX_ANIMALS % 2 != 0) {
            throw std::invalid_argument("MAX_ANIMALS must be a multiple of 2 and greater than 1");
        }
        const Animal* animals[MAX_ANIMALS] = {0};

        for (int i = 0; i < MAX_ANIMALS; i++) {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        for (int i = 0; i < MAX_ANIMALS; i++)
            animals[i]->display();
        for (int i = 0; i < MAX_ANIMALS; i++)
            delete animals[i];

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
