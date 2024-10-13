# 42-CPP-Modules

# Introduction

## What is a Class in C++?

A class is a user-defined data type, which holds its own data members and member functions, which can be accessed and used by creating an instance of that class. A C++ class is like a blueprint for an object.

## What is an Object in C++?

When a class is defined, only the specification for the object is defined; no memory or storage is allocated. To use the data and access functions defined in the class, you need to create objects.

## Accessing Data Members and Member Functions

The data members and member functions of the class can be accessed using the dot(‘.’) operator with the object.

## Access Modifiers

In C++ classes, we can control the access to the members of the class using Access Specifiers. Also known as access modifier, they are the keywords that are specified in the class and all the members of the class under that access specifier will have particular access level.

In C++, there are 3 access specifiers that are as follows:

Public: Members declared as public can be accessed from outside the class.
Private: Members declared as private can only be accessed within the class itself.
Protected: Members declared as protected can be accessed within the class and by derived classes.
If we do not specify the access specifier, the private specifier is applied to every member by default.

