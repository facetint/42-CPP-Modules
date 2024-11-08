## 42-CPP-Module-00 

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

   - ### Public: Members declared as public can be accessed from outside the class.
   
   - ### Private: Members declared as private can only be accessed within the class itself.
   
   - ### Protected: Members declared as protected can be accessed within the class and by derived classes.
   
   - ‼️ *Default Access:* If no access modifier is specified, the default access level is private.

```cpp
class MyClass {
private:
    int age;  // Private member

public:
    void setAge(int a) { age = a; }  // Public member function
};

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

