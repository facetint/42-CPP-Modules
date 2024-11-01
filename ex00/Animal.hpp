#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>

class Animal{

protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal();

    void        setType(const std::string type);
    std::string getType(void) const;

    virtual void    makeSound(void) const;
    void    whoAmI(void) const;

};

#endif