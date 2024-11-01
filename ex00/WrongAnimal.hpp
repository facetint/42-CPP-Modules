#ifndef WRONGANIMAL_HPP

# define WRONGANIMAL_HPP

# include <iostream>

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

};

#endif