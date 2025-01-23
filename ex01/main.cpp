#include "iter.hpp"

int main()
{
    int arr[] = {9, 8, 7};
    std::string arr2[] = {"42", "Türkiye", "facetint"};
    float arr3[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double arr4[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << RED <<  " **** int array ****" << RESET << std::endl;
    iter(arr, 3, print);
    std::cout << RED << "\n **** string array ****" << RESET << std::endl;
    iter(arr2, 3, print);
    std::cout << RED << "\n **** float array **** " << RESET << std::endl;
    iter(arr3, 5, print);
    std::cout << RED << "\n **** double array ****" << RESET << std::endl;
    iter(arr4, 5, print);

    return (0);
}