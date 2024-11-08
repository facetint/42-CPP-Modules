# 42-CPP-Modules

| Module         | GitHub Link                                                                    | Clone Command                                                               |
|----------------|--------------------------------------------------------------------------------|----------------------------------------------------------------------------|
| CPP-Module-00  | [CPP-Module-00](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-00) | `git clone -b CPP-Module-00 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-01  | [CPP-Module-01](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-01) | `git clone -b CPP-Module-01 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-02  | [CPP-Module-02](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-02) | `git clone -b CPP-Module-02 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-03  | [CPP-Module-03](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-03) | `git clone -b CPP-Module-03 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-04  | [CPP-Module-04](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-04) | `git clone -b CPP-Module-04 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-05  | [CPP-Module-05](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-05) | `git clone -b CPP-Module-05 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-06  | [CPP-Module-06](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-06) | `git clone -b CPP-Module-06 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-07  | [CPP-Module-07](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-07) | `git clone -b CPP-Module-07 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-08  | [CPP-Module-08](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-08) | `git clone -b CPP-Module-08 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-09  | [CPP-Module-09](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-09) | `git clone -b CPP-Module-09 https://github.com/facetint/42-CPP-Modules.git` |





## In the second way you can also access the projects in this way ⤵️ ⤵️ ⤵️

<img width="320" alt="Ekran Resmi 2024-10-05 21 41 17" src="https://github.com/user-attachments/assets/a273b32e-09d4-4cf5-8733-c4e2fb91a073">

# What is C++?

C++ was created by **Bjarne Stroustrup** in 1979 as an extension of the C programming language. It incorporates object-oriented principles, such as classes and objects, while retaining the low-level capabilities and system-level access of C. Over the years, C++ has evolved to support a variety of paradigms, including procedural, object-oriented, and generic programming.

## Key Features of C++

- **Object-Oriented Programming (OOP)**: C++ supports the principles of OOP, including classes, inheritance, polymorphism, and encapsulation. This allows for modular, maintainable, and reusable code.
  
- **Performance**: C++ is often the language of choice for high-performance applications due to its ability to interact directly with hardware. It allows precise memory management, enabling developers to optimize resource usage.

- **Standard Template Library (STL)**: The STL provides useful templates for various data structures (like vectors, lists, and maps) and algorithms, making it easier to work with common operations and data types.

- **Memory Management**: C++ gives developers direct control over memory management, allowing them to allocate and deallocate memory manually using operators such as `new` and `delete`.

- **Multiplatform**: C++ code can be compiled and executed on multiple platforms, including Windows, macOS, and Linux. It is used in many large-scale applications, from web browsers and operating systems to games and scientific simulations.

- **Low-Level Manipulation**: C++ provides low-level manipulation features, such as pointers and direct memory access, which are essential for system-level programming.

## C++ Syntax and Basics

C++ uses a combination of both low-level and high-level constructs. Here's a simple example of a C++ program:

```cpp
#include <iostream>  // Include standard library for input-output operations

using namespace std;  // To use standard functions without prefixing with std::

int main() {
    // Output to the console
    cout << "Hello, C++ World!" << endl;
    return 0;
}
```
## Key Concepts

### Variables and Data Types:

C++ supports multiple data types, including integer (int), floating-point (float, double), character (char), boolean (bool), and more.

```cpp
int age = 25;
float height = 5.9;
char gender = 'M';
bool isActive = true;
````

### Functions:

Functions in C++ allow you to encapsulate logic for reuse. They can take parameters and return values.

```cpp
int add(int a, int b) {
    return a + b;
}
```

### Control Structures:

C++ includes standard control structures like if, else, for, while, and switch to manage the flow of execution.

```cpp
if (age > 18) {
    cout << "Adult" << endl;
}
else {
    cout << "Minor" << endl;
}
```

### Object-Oriented Programming (OOP):

C++ supports the use of classes and objects. A class is a blueprint for creating objects (instances of the class).

```cpp
class Car {
public:
    string make;
    string model;
    int year;

    void display() {
        cout << make << " " << model << " (" << year << ")" << endl;
    }
};

int main() {
    Car myCar;
    myCar.make = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2021;
    myCar.display();
}

````

### Pointers and References:

C++ allows direct memory manipulation through pointers and references.

```cpp
int x = 10;
int* ptr = &x;  // Pointer to variable x
cout << "Value of x: " << *ptr << endl;  // Dereferencing the pointer
```

### Exception Handling:

C++ provides a robust exception handling mechanism with try, catch, and throw.

```cpp
try {
    int result = 10 / 0;  // Division by zero
}
catch (const exception& e) {
    cout << "Exception: " << e.what() << endl;
}
```


