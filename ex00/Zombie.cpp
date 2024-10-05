#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << this->_name << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << "Zombie destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << this->_name << ">: BraiiiiiiinnnzzzZ..." << std::endl;
}
