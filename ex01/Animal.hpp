#ifndef ANIMAL_HPP

# define ANIMAL_HPP

# include <iostream>

# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define WHITE_COLOR "\x1b[38;2;255;255;255;01m"

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