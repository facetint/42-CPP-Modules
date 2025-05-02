## 42-CPP-Module-07

## Installation

```
git clone -b CPP-Module-07 https://github.com/facetint/42-CPP-Modules.git
```


# 🧩 C++ Templates

Templates are one of the most powerful and flexible features of C++. They enable writing generic and reusable code, enhancing both the functionality and efficiency of your programs. This document provides an in-depth exploration of C++ templates, including their syntax, use cases, and advanced features.

## 📚 Table of Contents

- [1. Introduction to Templates](#1-introduction-to-templates)
- [2. Template Syntax](#2-template-syntax)
  - [2.1 Function Templates](#21-function-templates)
  - [2.2 Class Templates](#22-class-templates)
  - [2.3 Template Specialization](#23-template-specialization)
- [3. Benefits of Using Templates](#3-benefits-of-using-templates)
- [4. Advanced Template Features](#4-advanced-template-features)
  - [4.1 Template Metaprogramming](#41-template-metaprogramming)
  - [4.2 Variadic Templates](#42-variadic-templates)
  - [4.3 SFINAE (Substitution Failure Is Not An Error)](#43-sfinae-substitution-failure-is-not-an-error)
- [5. Template Best Practices](#5-template-best-practices)

---

## 1. Introduction to Templates

In C++, templates allow you to write generic code that works with any data type. Templates allow functions and classes to operate with any type of data, provided that the data type supports the required operations. Templates are defined once but can be used with any data type.

Templates support both **function templates** and **class templates**.

---

## 2. Template Syntax

### 2.1 Function Templates

Function templates enable you to create functions that can handle any data type. Instead of writing a separate function for each type, you define a template function that can operate on any type.

#### Example:

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    int sumInt = add(5, 3);  // Calls add<int>
    double sumDouble = add(5.5, 3.2);  // Calls add<double>
}

```

In this example, add is a function template. It can be used with int, double, or any other type that supports the + operator.


### 2.2 Class Templates


Class templates enable the creation of classes that can work with any data type. This allows you to write a single class definition that can be used with different types.

**Example:**


```cpp
template <typename T>
class Box {
private:
    T value;
public:
    Box(T val) : value(val) {}
    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);
    Box<double> doubleBox(5.5);
    std::cout << intBox.getValue() << std::endl;  // Outputs: 10
    std::cout << doubleBox.getValue() << std::endl;  // Outputs: 5.5
}

```

Here, the Box class template can store any type T. We can create instances of Box with int, double, or any other data type.

### 2.3 Template Specialization


Template specialization allows you to define a different implementation of a template for a specific type. This is useful when a general template is not suitable for certain types.

**Example:**

```cpp
template <typename T>
class Printer {
public:
    void print(T t) {
        std::cout << t << std::endl;
    }
};

// Specialization for bool type
template <>
class Printer<bool> {
public:
    void print(bool b) {
        std::cout << (b ? "True" : "False") << std::endl;
    }
};

int main() {
    Printer<int> intPrinter;
    Printer<bool> boolPrinter;
    intPrinter.print(42);  // Outputs: 42
    boolPrinter.print(true);  // Outputs: True
}
```


In this example, we provide a specialized implementation for bool to print "True" or "False" instead of 1 or 0.

## 3. Benefits of Using Templates


  + **Code Reusability:** Templates allow you to write generic code that can be used with different data types, avoiding code duplication.

  + **Type Safety:** Templates provide compile-time type checking, which makes sure that the correct type is used.

  + ** Performance:** Templates often result in more efficient code since they allow type-specific optimizations by the compiler.


## 4. Advanced Template Features


### 4.1 Template Metaprogramming

  Template metaprogramming (TMP) is the use of templates to perform computations during compile time. This technique allows you to generate code based on types and values, optimizing runtime performance.

**Example:**

  Template metaprogramming allows for very powerful techniques, such as compile-time constants and type transformations.

### 4.2 Variadic Templates

  Variadic templates allow you to define templates that take an arbitrary number of template arguments. They provide a flexible mechanism for handling types in an extensible way.


### 4.3 SFINAE (Substitution Failure Is Not An Error)

  SFINAE is a C++ template feature that allows you to enable or disable templates based on the properties of types. This allows you to create highly flexible and type-safe code.


## 5 Template Best Practices

| Practice                                     | Description                                                                                                                                          |
|---------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Minimize Template Complexity**            | Complex templates can be hard to read and maintain. Keep them simple and focused to improve code clarity.                                           |
| **Use Type Traits**                         | Leverage standard type traits (from `<type_traits>`) to simplify template logic and improve readability, especially when using SFINAE.              |
| **Avoid Overuse of Template Specialization**| Template specialization is powerful but can lead to overly complex code. Use it sparingly and only when absolutely necessary.                       |
| **Always Use `typename` for Dependent Types**| When accessing nested types in dependent types, use the `typename` keyword to avoid ambiguity and ensure correct parsing by the compiler.           |





