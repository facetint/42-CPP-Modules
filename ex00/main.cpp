#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << PURPLE " Testing with std::vector<int>" RESET << std::endl;
    testEasyFind(vec, 30); 
    testEasyFind(vec, 99);

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    lst.push_back(45);

    std::cout << PURPLE "\n Testing with std::list<int>" RESET << std::endl;
    testEasyFind(lst, 25);
    testEasyFind(lst, 99);

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    deq.push_back(400);
    deq.push_back(500);

    std::cout << PURPLE "\n Testing with std::deque<int>" RESET << std::endl;
    testEasyFind(deq, 200);
    testEasyFind(deq, 999);

    return 0;
}
