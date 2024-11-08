#include "Point.hpp"
#include "Fixed.hpp"

int main() {
    Point a(1, 1);
    Point b(1, 5);
    Point c(5, 5);
    Point p(3, 3);

    if (bsp(a, b, c, p))
        std::cout << "inside " << "the triangle" << std::endl;
    else
        std::cout << "outside " << "the triangle" << std::endl;
}
