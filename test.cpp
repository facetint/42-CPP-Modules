#include <iostream>

int main()
{
    std::string str;
    int x;
    char c;
    char a[] = "fatma";


    str = "yusuf";
    x = 97;
    c = 'a';

    std::cout << c << std::endl;

    std::cout << static_cast <int> (c) << std::endl;
   

    std::cout << x << std::endl;

    std::cout << static_cast <char> (x) << std::endl;


    // std::cout << str << std::endl;

    // std::cout << static_cast <int> (str) << std::endl;

     std::cout << a << std::endl;

    //std::cout << static_cast <int*> (a) << std::endl;

    std::cout << reinterpret_cast <int*> (a[3]) << std::endl;


}
