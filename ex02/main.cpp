#include "Base.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
    int rand = 1 + std::rand() % 3;
	if (rand == 1)
	{
		std::cout << "Generate A" << std::endl;
		return new A();
	}
	else if (rand == 2)
	{
		std::cout << "Generate B" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "Generate C" << std::endl;
		return new C();
	}

}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
		std::cout << "  (identify Base*) Can't identify this Base*..." << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B &>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch (std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C &>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch (std::exception &e)
            {
                std::cout << "  (identify Base&) Can't identify this Base&..." << std::endl;
            }
        }
    }
}

int main()
{
    try
    {
        std::srand(std::time(0));

        for (size_t cur = 0; cur < 3; cur++)
        {
            std::cout << "Iteration " << cur + 1 << ":" << std::endl;

            Base *randBase = generate();

            std::cout << "Identify by pointer: ";
            identify(randBase);

            std::cout << "Identify by reference: ";
            identify(*randBase);

            delete randBase;

            std::cout << "------------------------" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "An error occurred: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
