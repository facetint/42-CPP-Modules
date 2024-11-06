#ifndef CAT_HPP

# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
    Brain *brain;
    int ideaIndex;

public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound() const;
    Brain *getBrain() const;
    void display(void) const;

};

#endif