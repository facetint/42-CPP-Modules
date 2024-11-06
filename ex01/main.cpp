#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "\n=== Testing Animal Hierarchy ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "Type of dog: " << dog->getType() << std::endl;
    std::cout << "Type of cat: " << cat->getType() << std::endl;

    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== Testing WrongAnimal Hierarchy ===" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Type of wrongCat: " << wrongCat->getType() << std::endl;

    Cat cat2;
    Cat cat3 = cat2;
    wrongMeta->makeSound();
    wrongCat->makeSound();

    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Testing Deep Copy Dog ===" << std::endl;

    Dog basicDog;
    {
        basicDog.getBrain()->setIdea(0, "I am a dog");
        Dog tmpDog = basicDog;
        std::cout << "Dog idea: " << tmpDog.getBrain()->getIdea(0) << std::endl;
        basicDog.getBrain()->setIdea(0, "I am a cat");
        std::cout << "Dog idea: " << tmpDog.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog idea: " << basicDog.getBrain()->getIdea(0) << std::endl;
    }

    std::cout << "\n=== Testing Deep Copy Cat ===" << std::endl;

    Cat basicCat;
    {
        Cat tmpCat = basicCat;
    }

    std::cout << "===============================" << std::endl;
    Dog dog1;
    Cat cat1;

    dog1.getBrain()->setIdea(0, "I am a dog");
    cat1.getBrain()->setIdea(0, "I am a cat");

    std::cout << "Dog idea: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "Cat idea: " << cat1.getBrain()->getIdea(0) << std::endl;

    std::cout << "===============================" << std::endl;


    return 0;
}