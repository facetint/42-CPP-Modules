#ifndef WRONGCAT_HPP

# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define WHITE_COLOR "\x1b[38;2;255;255;255;01m"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);
    ~WrongCat();
    void makeSound() const;
    void display(void) const;
};

#endif