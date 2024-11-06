#include "Character.hpp"

Character::Character() : _name("Character")
{
    std::cout << "Default constructor called - (Character)" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
}

Character::Character(std::string const& name) : _name(name)
{
    std::cout << "Parametric constructor called - (Character)" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character& other)
{
    *this = other;
    std::cout << "Copy constructor called - (Character)" << std::endl;
}

Character::~Character()
{
    std::cout << "Destructor called - (Character)" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] != NULL)
        {
            delete this->_inventory[i];
        }
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i] != NULL)
                delete this->_inventory[i];
            if (other._inventory[i] != NULL)
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    std::cout << "Assignation operator called - (Character)" << std::endl;
    return *this;
}

std::string const& Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        this->_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
    {
        this->_inventory[idx]->use(target);
    }
}
