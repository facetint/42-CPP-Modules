#include "MutantStack.hpp"
#include <iostream>
#include <list>

void testMutantStack()
{
    std::cout << BLUE "===== Testing MutantStack =====" RESET << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout <<  WHITE "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Elements in MutantStack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << RESET << std::endl;

    std::stack<int> s(mstack);
}

void testList()
{
    std::cout << BLUE "\n ===== Testing std::list =====" RESET << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << WHITE "Last element: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "Elements in std::list:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << RESET <<  std::endl;
}

int main()
{
    testMutantStack();
    std::cout << WHITE "=============================" RESET << std::endl;
    testList();

    return 0;
}
