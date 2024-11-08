# 42-CPP-Module-00


# Table of Contents

1. [What is a Class in C++?](#what-is-a-class-in-c)
2. [What is an Object in C++?](#what-is-an-object-in-c)
3. [Accessing Data Members and Member Functions](#accessing-data-members-and-member-functions)
4. [Access Modifiers](#access-modifiers)
   - [Public](#public)
   - [Private](#private)
   - [Protected](#protected)
5. [Member Function in C++ Classes](#member-function-in-c-classes)
   - [Inside Class Definition](#inside-class-definition)
   - [Outside Class Definition](#outside-class-definition)
6. [Namespaces](#namespaces)
7. [Initialization Lists](#initialization-lists)
8. [Constructor](#constructor)
   - [Main Features](#main-features)
9. [Destructor](#destructor)
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

## Accessing Data Members and Member Functions

The data members and member functions of the class can be accessed using the dot(‘.’) operator with the object.

## Access Modifiers

In C++ classes, we can control the access to the members of the class using Access Specifiers. Also known as access modifier, they are the keywords that are specified in the class and all the members of the class under that access specifier will have particular access level.

In C++, there are 3 access specifiers that are as follows:

**Public:** Members declared as public can be accessed from outside the class.
**Private:** Members declared as private can only be accessed within the class itself.
**Protected:** Members declared as protected can be accessed within the class and by derived classes.
If we do not specify the access specifier, the private specifier is applied to every member by default.


## Member Function in C++ Classes

There are 2 ways to define a member function:

Inside class definition
Outside class definition
Till now, we have defined the member function inside the class, but we can also define the member function outside the class. To define a member function outside the class definition,

We have to first declare the function prototype in the class definition.
Then we have to use the scope resolution:: operator along with the class name and function name.


## Namespaces

Namespaces are used to avoid name conflicts. Especially in large projects or when working with different libraries, there may be classes or functions with the same name. Separating these names using namespaces makes the code easier to read and maintain. The `::` operator is used to access elements within a namespace.


## Initialization Lists

Initialization lists are used to assign initial values to data members in the constructor. This method improves performance and is especially necessary when initializing variables of type `const` or reference.

## Constructor

In C++, a “constructor” is a special function that is automatically called when a new object of a class is created. Constructors are used to set the initial state of the object and have the same name as the name of the class. Constructors are typically used to set the resources required when creating an object.

**Main Features**

1. **Same Name**: The constructor has the same name as the class.
2. **No Return Type**: Constructors have no return type (not even void).
3. **Called Automatically**: Called automatically when the object is created.
4. **Overloadable**: Multiple constructors can be defined with different parameter sets (constructor overloading).


## DESTRUCTOR

- Destructor is a special member method used to end the life of a class and release the resources that the class owns. The destructor of a class is automatically called when its object is released from a scope or freed from memory with the *"delete ”* operator.
- **Destructor is defined as “*~ (Tilda)className()*”. Here the “~” sign represents that this method is a Destructor. Unlike Constructors, Destructors only have to be one.

 **Why do we need a Destructor?**
- We use it to prevent leaks. By freeing the dynamic memory addresses we use in the class, we have a clean and readable code.
- At the same time, since this method is automatically executed at the end of the class lifetime, we don't need to intervene manually.

