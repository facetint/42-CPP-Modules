#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << this->_name << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << "Zombie destroyed" << std::endl;
}
