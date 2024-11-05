#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>
# define RED_COLOR "\x1b[31;01m"
# define RESET "\x1b[0m"
# define GREEN_COLOR "\x1b[32;01m"
# define BLUE_COLOR "\x1b[34;01m"
# define PURPLE_COLOR "\x1b[38;2;178;58;238;01m"
# define WHITE_COLOR "\x1b[38;2;255;255;255;01m"


class WrongAnimal{

protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);
    ~WrongAnimal();

    void        setType(const std::string type);
    std::string getType(void) const;

    void    makeSound(void) const;
    void display(void) const;

};

#endif