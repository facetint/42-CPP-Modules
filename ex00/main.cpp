#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongCat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->display();
    j->display();
    meta->display();
    k->display();

    delete k;
    delete meta;
    delete j;
    delete i;

    std::cout << GREEN_COLOR "=== WrongAnimal Test ===" << RESET << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout <<  wrongCat->getType() << " " << std::endl;

    wrongCat->display();
    wrongMeta->display();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
