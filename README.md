e## 42-CPP-Module-00 

## Installation

```
git clone -b CPP-Module-00 https://github.com/facetint/42-CPP-Modules.git
```


# Table of Contents

- [What is a Class in C++?](#what-is-a-class-in-c)
- [What is an Object in C++?](#what-is-an-object-in-c)
- [Accessing Data Members and Member Functions](#accessing-data-members-and-member-functions)
- [Access Modifiers](#access-modifiers)
   - [Public](#public)
   - [Private](#private)
   - [Protected](#protected)
- [C++ Standard I/O Streams](#c-standard-i/o-streams)
   - [1. Standard Input and Output Streams](#standart-input-and-output-streams)
   - [2. Basic Stream Operators](#2-basic-stream-operator)
   - [3. Stream Manipulators](#3stream-manipulators)
   - [4. Buffering and Flush](#4-bufferind-and-flush)
   - [5. File I/O Streams](#5-file-i/o-streams)
- [Member Function in C++ Classes](#member-function-in-c-classes)
   - [Inside Class Definition](#inside-class-definition)
   - [Outside Class Definition](#outside-class-definition)
- [Namespaces](#namespaces)
- [Initialization Lists](#initialization-lists)
- [Constructor](#constructor)
   - [Main Features](#main-features)
- [Destructor](#destructor)
   - [Why do we need a Destructor?](#why-do-we-need-a-destructor)


# What is a Class in C++?

   A class is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.


**A class serves as a blueprint for creating objects in C++. Here's an example:**

```cpp
class Car {
public:
    string model;
    int year;

    void start() {
        cout << "The car is starting." << endl;
    }
};
```
## What is an Object in C++?

   When a class is defined, only the specification for the object is defined; no memory or storage is allocated. To use the data and access functions defined in the class, you need to create objects.

```cpp

Car myCar;  // myCar is an object of the Car class
myCar.model = "Tesla";
myCar.year = 2022;
myCar.start();  // Calls the start method
```

## Accessing Data Members and Member Functions

   The data members and member functions of the class can be accessed using the dot(‘.’) operator with the object.

```cpp

myCar.model = "Tesla";  // Accessing the data member
myCar.start();          // Calling the member function
```

## Access Modifiers

   In C++ classes, we can control the access to the members of the class using Access Specifiers. Also known as access modifier, they are the keywords that are specified in the class and all the members of the class under that access specifier will have particular access level.

In C++, there are 3 access specifiers that are as follows:

   - ### Public: 
   Members declared as public can be accessed from outside the class.
   
   - ### Private: 
   Members declared as private can only be accessed within the class itself.
   
   - ### Protected: 
   Members declared as protected can be accessed within the class and by derived classes.
   
   - ‼️ *Default Access:* If no access modifier is specified, the default access level is private.

```cpp
class MyClass {
private:
    int age;  // Private member

public:
    void setAge(int a) { age = a; }  // Public member function
};

```

## C++ Standard I/O Streams

In C++, standard input/output (I/O) streams are used to read data from the user and display data to the user. These streams are part of the **`<iostream>`** header and include:

### 1. Standard Input and Output Streams

   - **`std::cout`**: Used for displaying output to the console.
     - The "console output" object is used with the `<<` operator to direct data from left to right.
   - std::cin: Used to get input from the user.

The "console input" object reads data into variables via the >> operator.

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
````
   - std::cerr: Used to output error messages.
      -"Console error" is helpful for debugging or informing users of mistakes.

```cpp
std::cerr << "An error occurred!" << std::endl;
```

   -std::clog: Used to display log or debug messages.
      - Useful for outputting logs and additional details about program execution.

```cpp
std::clog << "Logging message." << std::endl;
````

### 2. Basic Stream Operators

#### << (insertion operator): 
   - Used with std::cout to direct data to the console or another output stream.
#### >> (extraction operator): 
   - Used with std::cin to receive input data from the console into a variable.

   - Multiple streams can be chained together for efficient output:

```cpp
std::cout << "Hello, " << "World!" << std::endl;
````

### 3. Stream Manipulators
Stream manipulators format the output or input. Some commonly used manipulators include:

   - std::endl: Inserts a newline and flushes the output buffer.
   - std::setw: Sets a specific width (useful for tables).
   - std::fixed and std::setprecision: Controls the number of decimal places.
   - std::boolalpha and std::noboolalpha: Displays Boolean values as "true" or "false" instead of 1 or 0.

Example:

```cpp 
#include <iostream>
#include <iomanip> // Required for setw, setprecision

int main() {
    double pi = 3.14159;
    std::cout << std::fixed << std::setprecision(2) << pi << std::endl; // Outputs 3.14
    return 0;
}
````

### 4. Buffering and Flush

Streams typically buffer data, meaning the output is delayed until the buffer is full or flushed.

   - std::flush: Manually flushes the buffer, forcing data to be output immediately.

### 5. File I/O Streams

File handling in C++ is done via <fstream> which includes std::ifstream, std::ofstream, and std::fstream for file operations.

   - std::ifstream: Used for reading data from files.
   - std::ofstream: Used for writing data to files.
   - std::fstream: Used for both reading and writing data.

Example:

```cpp
#include <fstream>
#include <iostream>

int main() {
    std::ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << "This is a line in the file.\n";
        outFile.close();
    }
    return 0;
}
````

Summary
   - std::cout: Outputs to console.
   - std::cin: Receives input from console.
   - std::cerr: Outputs error messages.
   - std::clog: Outputs log messages.
   - std::ofstream, std::ifstream, std::fstream: File I/O operations.

  ```cpp
  #include <iostream>

  int main() {
      std::cout << "Hello, World!" << std::endl;
      return 0;
  }
```

## Member Function in C++ Classes

There are 2 ways to define a member function:

### Inside Class Definition

You can define a member function directly inside the class definition.

```cpp
class MyClass {
public:
    void sayHello() {
        cout << "Hello!" << endl;
    }
};
```

### Outside Class Definition

   Alternatively, you can declare the function inside the class and define it outside using the scope resolution operator (::).

```cpp
class MyClass {
public:
    void sayHello();
};

void MyClass::sayHello() {
    cout << "Hello from outside the class!" << endl;
}
```

🟥 Till now, we have defined the member function inside the class, but we can also define the member function outside the class. To define a member function outside the class definition, we have to first declare the function prototype in the class definition.Then we have to use the scope resolution:: operator along with the class name and function name.


## Namespaces

   Namespaces are used to avoid name conflicts. Especially in large projects or when working with different libraries, there may be classes or functions with the same name. Separating these names using namespaces makes the code easier to read and maintain. The `::` operator is used to access elements within a namespace.

```cpp
namespace MyNamespace {
    class MyClass {
    public:
        void display() {
            cout << "Inside MyNamespace" << endl;
        }
    };
}
```
♦️ To use members of a namespace:

```cpp
MyNamespace::MyClass obj;
obj.display();
```

## Initialization Lists

   Initialization lists are used to assign initial values to data members in the constructor. This method improves performance and is especially necessary when initializing variables of type `const` or reference.

```cpp
class MyClass {
    const int x;
public:
    MyClass(int value) : x(value) {}
};
```

## Constructor

   In C++, a “constructor” is a special function that is automatically called when a new object of a class is created. Constructors are used to set the initial state of the object and have the same name as the name of the class. Constructors are typically used to set the resources required when creating an object.

**Main Features**

   1. **Same Name**: The constructor has the same name as the class.

   2. **No Return Type**: Constructors have no return type (not even void).

   3. **Called Automatically**: Called automatically when the object is created.

   4. **Overloadable**: Multiple constructors can be defined with different parameter sets (constructor overloading).

```cpp
class Car {
public:
    string model;
    int year;

    Car(string m, int y) : model(m), year(y) {}
};
```

## DESTRUCTOR

   - Destructor is a special member method used to end the life of a class and release the resources that the class owns. The destructor of a class is automatically called when its object is released from a scope or freed from memory with the *"delete ”* operator.
   - **Destructor is defined as “*~ (Tilda)className()*”. Here the “~” sign represents that this method is a Destructor. Unlike Constructors, Destructors only have to be one.

 **Why do we need a Destructor?**

   - We use it to prevent leaks. By freeing the dynamic memory addresses we use in the class, we have a clean and readable code.
   - At the same time, since this method is automatically executed at the end of the class lifetime, we don't need to intervene manually.


```cpp
class Car {
public:
    Car() {
        cout << "Car is created!" << endl;
    }

    ~Car() {  // Destructor
        cout << "Car is destroyed!" << endl;
    }
};
```

