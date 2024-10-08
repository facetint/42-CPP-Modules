#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    int num = 5;
    zombie = zombieHorde(num, "Zombie");
    for (int i = 0; i < num; i++)
    {
        zombie[i].announce();
    }
    delete[] zombie;
    return (0);
}
