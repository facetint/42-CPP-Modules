#ifndef AANIMAL_HPP

# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        AAnimal(const AAnimal& other);
        virtual ~AAnimal();
        AAnimal& operator=(const AAnimal& other);
        void setType(const std::string type);
        std::string getType(void) const;
        virtual void makeSound() const = 0;
        virtual void display() const = 0;
};

#endif