#include "iter.hpp"

void print(int &i)
{
    std::cout << i << " ";
}

void print(std::string &str)
{
    std::cout << str << " ";
}

int main()
{
    int arr[] = {9, 8, 7};
    iter(arr, 3, print);
    std::cout << std::endl;

    std::string arr2[] = {"42", "Türkiye", "-" , "facetint"};
    iter(arr2, 4, print);
    std::cout << std::endl;

    return (0);
}