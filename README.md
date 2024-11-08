# 42-CPP-Module-03

## Installation

```
git clone -b CPP-Module-03 https://github.com/facetint/42-CPP-Modules.git
```

# Table of Contents

- [Inheritance in C++](#inheritance-in-c++)
- [Basic Concepts of Inheritance](#basic-concepts-of-inheritance)
  - [Base Class](#base-class)
  - [Derived Class](#derived-class)
  - [Access Specifier](#access-specifier)
  - [Note](#note)
- [Modes of Inheritance in C++](#modes-of-inheritance-in-c++)
  - [Public Inheritance Mode](#public-inheritance-mode)
  - [Protected Inheritance Mode](#protected-inheritance-mode)
  - [Private Inheritance Mode](#private-inheritance-mode)
- [Types of Inheritance in C++](#types-of-inheritance-in-c++)
  - [Single Inheritance](#single-inheritance)
  - [Multiple Inheritance](#multiple-inheritance)
  - [Multilevel Inheritance](#multilevel-inheritance)
  - [Hierarchical Inheritance](#hierarchical-inheritance)
  - [Hybrid Inheritance](#hybrid-inheritance)
- [Diamond Problem](#diamond-problem)
  - [Diamond Problem Explained](#diamond-problem-explained)
  - [Example Code](#example-code)
  - [Solution Methods](#solution-methods)
    - [Virtual Inheritance](#virtual-inheritance)
    - [Method Selection](#method-selection)


# Inheritance

In C++, inheritance is an object-oriented programming (OOP) concept that allows a class to inherit features and methods from another class. Inheritance is used to reduce code duplication, create hierarchy between classes, and create a more organized structure.

## Basic Concepts of Inheritance

**Base Class:** The class from which other classes inherit. The base class defines general properties and behaviors.

**Derived Class:** A class that inherits properties and methods from the base class. It can add extra properties and behaviors. 

**Access Specifier:** Rules that determine how members of the base class are accessed in derived classes during inheritance.

**!!Note:** A derived class doesn’t inherit access to private data members. However, it does inherit a full parent object, which contains any private members which that class declares.

Example:

```cpp
#include <iostream>

class Animal {
public:
    void makeSound() {
        std::cout << "Animal is making a sound." << std::endl;
    }
};

class Flying {
public:
    void fly() {
        std::cout << "Flying!" << std::endl;
    }
};

class Bird : public Animal, public Flying {
public:
    void sing() {
        std::cout << "Bird is singing." << std::endl;
    }
};

int main() {
    Bird bird;
    bird.makeSound();  // Method from the Animal class
    bird.fly();        // Method from the Flying class
    bird.sing();       // Method from the Bird class

    return 0;
}
```



![image](https://github.com/user-attachments/assets/189064da-0423-435f-8d6b-6143cfbb93ce)


## Modes of Inheritance in C++

Mode of inheritance controls the access level of the inherited members of the base class in the derived class. In C++, there are 3 modes of inheritance:

- Public Mode
- Protected Mode
- Private Mode

**Public Inheritance Mode**

If we derive a subclass from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in the derived class.

**Protected Inheritance Mode**

If we derive a subclass from a Protected base class. Then both public members and protected members of the base class will become protected in the derived class.

**Private Inheritance Mode**

If we derive a subclass from a Private base class. Then both public members and protected members of the base class will become private in the derived class. They can only be accessed by the member functions of the derived class.
Private mode is the default mode that is applied when we don’t specify any mode.


![image](https://github.com/user-attachments/assets/92e0ea15-a543-454c-b28e-fa1a2c5db493)


## Types Of Inheritance in C++


![image](https://github.com/user-attachments/assets/c49635aa-f8b6-4c7c-ae4a-9765d651e460)


**1. Single Inheritance**

In single inheritance, a class is allowed to inherit from only one class. i.e. one base class is inherited by one derived class only.

**2. Multiple Inheritance**

Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one subclass is inherited from more than one base class.        


**3. Multilevel Inheritance**

In this type of inheritance, a derived class is created from another derived class and that derived class can be derived from a base class or any other derived class. There can be any number of levels.

**4. Hierarchical Inheritance**

In this type of inheritance, more than one subclass is inherited from a single base class. i.e. more than one derived class is created from a single base class.

**5. Hybrid Inheritance**

Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance will create hybrid inheritance in C++

There is no particular syntax of hybrid inheritance.


![image](https://github.com/user-attachments/assets/3b7c7621-6ad6-4467-a5e9-08dd5484ca94)


## Diamond Problem

It is a situation that arises in cases of multiple inheritance. This problem occurs when a class inherits the same superclass in two different ways. Below I provide more information about the diamond problem and a solution method.

*Diamond Problem Explained*

Consider the following structure:

       A
      / \
     B   C
      \ /
       D

Here:

ClassA is inherited by classes B and C.
ClassD inherits both classes B and C.
If we define a method in class A and class D calls this method of class A through classes B and C, it becomes unclear which path to use. This leads to the diamond problem.

*Example Code*

```cpp
#include <iostream>

class A {
public:
    void speak() {
        std::cout << "A speaks!" << std::endl;
    }
};

class B : public A {
public:
    void speak() {
        std::cout << "B speaks!" << std::endl;
    }
};

class C : public A {
public:
    void speak() {
        std::cout << "C speaks!" << std::endl;
    }
};

class D : public B, public C {
public:
    void speak() {
        // Which speak() method should we call?
        // A::speak(); // This cannot be used directly
        B::speak(); // We can call B's speak() method
    }
};

int main() {
    D d;
    d.speak(); // Here we must specify which speak() method to call

    return 0;
}
```

**Solution Methods**

*Virtual Inheritance:* This is the most common way to solve the diamond problem in C++. By defining classA as a virtual superclass, we allow classes B and C to use class A as a single object.

```cpp
class A {
public:
    void speak() {
        std::cout << "A speaks!" << std::endl;
    }
};

class B : virtual public A {
public:
    void speak() {
        std::cout << "B speaks!" << std::endl;
    }
};

class C : virtual public A {
public:
    void speak() {
        std::cout << "C speaks!" << std::endl;
    }
};

class D : public B, public C {
public:
    void speak() {
        A::speak(); // A'nın speak() metodunu çağırıyoruz
    }
};

int main() {
    D d;
    d.speak(); // A speaks!

    return 0;
}
```

*2- Method Selection:* Within classD, you can explicitly specify which method you want to call from class A, B or C. This removes ambiguity by choosing a specific path.
