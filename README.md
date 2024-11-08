# 42-CPP-Modules

## Installation

```
git clone -b CPP-Module-02 https://github.com/facetint/42-CPP-Modules.git
```

| Module              | GitHub Link                                                | Clone Command                                                      |
|---------------------|------------------------------------------------------------|--------------------------------------------------------------------|
| CPP-Module-00       | [CPP-Module-00](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-00) | `git clone -b CPP-Module-00 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-01       | [CPP-Module-01](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-01) | `git clone -b CPP-Module-01 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-02       | [CPP-Module-02](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-02) | `git clone -b CPP-Module-02 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-03       | [CPP-Module-03](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-03) | `git clone -b CPP-Module-03 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-04       | [CPP-Module-04](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-04) | `git clone -b CPP-Module-04 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-05       | [CPP-Module-05](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-05) | `git clone -b CPP-Module-05 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-06       | [CPP-Module-06](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-06) | `git clone -b CPP-Module-06 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-07       | [CPP-Module-07](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-07) | `git clone -b CPP-Module-07 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-08       | [CPP-Module-08](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-08) | `git clone -b CPP-Module-08 https://github.com/facetint/42-CPP-Modules.git` |
| CPP-Module-09       | [CPP-Module-09](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-09) | `git clone -b CPP-Module-09 https://github.com/facetint/42-CPP-Modules.git` |


# Table of Contents

- [The Orthodox Canonical Class Form](#the-orthodox-canonical-class-form)
- [Fixed-Point Numbers](#fixed-point-numbers)
  - [What is a Fixed-Point Number?](#what-is-a-fixed-point-number)
  - [Key Features of Fixed-Point Numbers](#key-features-of-fixed-point-numbers)
  - [Use Cases of Fixed-Point Numbers](#use-cases-of-fixed-point-numbers)
  - [Fixed-Point Representation Example](#fixed-point-representation-example)
  - [Example Code for Fixed-Point Numbers](#example-code-for-fixed-point-numbers)
- [Floating Point Numbers](#floating-point-numbers)
  - [Structure of a Floating-Point Number](#structure-of-a-floating-point-number)
  - [IEEE 754 Single Precision (32-bit)](#ieee-754-single-precision-32-bit)
  - [Floating Point Representation](#floating-point-representation)
  - [Example - IEEE 754 Single Precision](#example-ieee-754-single-precision)
- [Differences Between Fixed-Point and Floating-Point Numbers](#differences-between-fixed-point-and-floating-point-numbers)
- [Operator Overloading in C++](#operator-overloading-in-c++)
  - [Why Use Operator Overloading?](#why-use-operator-overloading)
  - [Basic Rules of Operator Overloading](#basic-rules-of-operator-overloading)
  - [Syntax for Operator Overloading](#syntax-for-operator-overloading)
    - [Overloading Operators as Member Functions](#overloading-operators-as-member-functions)

## The Orthodox Canonical Class Form

The **Orthodox Canonical Class Form** is a set of special member functions that should be defined to manage resource allocation and prevent common issues like memory leaks and unexpected behavior. These functions are:

- **A Default Constructor**: Used internally to initialize objects and data members when no other value is available.
- **A Copy Constructor**: Used in the implementation of call-by-value parameters.
- **An Assignment Operator**: Used to assign one value to another.
- **A Destructor**: Invoked when an object is deleted.

The purpose of this form is to prevent memory leaks, copy errors, and unnecessary copies in classes that require resource management. For example, if a class dynamically allocates memory, it needs to perform memory management properly when copied or moved. 

If these special member functions are not defined, C++ automatically provides a copy constructor and copy assignment operator by default. However, these default implementations do not guarantee that resources are managed correctly, which can lead to memory leaks or unexpected behavior.

---

## Fixed-Point Numbers

### What is a Fixed-Point Number?

A **fixed-point number** is a method of representing numerical values where the number of decimal places is fixed. Fixed-point numbers are particularly useful in embedded systems or applications requiring high performance and limited memory, as they allow fractional numbers to be represented with a fixed number of decimal points.

In fixed-point notation, part of the number is the integer part, and the other part is the fractional part. This allows fractional values to be represented similarly to floating-point numbers but with a fixed number of decimal places.

### Key Features of Fixed-Point Numbers

- **Fixed Decimal Point**: Unlike floating-point numbers, the decimal point in fixed-point numbers remains in a fixed position. For example, the last 8 bits can represent the fractional part. Thus, the number `123.45` can be stored as `12345`, and the location of the decimal point is predetermined.
  
- **Precision and Scaling**: Fixed-point numbers are stored as integers and scaled by a fixed factor. For instance, if we scale by 256, the number `1.5` is stored as `384`, and `384 / 256 = 1.5`.

- **Difference from Floating-Point Numbers**: Fixed-point numbers have fixed precision with a limited number of decimal places, making them faster but less flexible than floating-point numbers.

### Use Cases of Fixed-Point Numbers

Fixed-point representation is widely used in embedded systems, game programming, and digital signal processing (DSP), where limited hardware resources must handle fractional number calculations efficiently.

### Fixed-Point Representation Example

In an **8.8 fixed-point** representation, the first 8 bits represent the integer part, and the last 8 bits represent the fractional part.

| Integer Part (8 bits) | Fractional Part (8 bits) |
|-----------------------|--------------------------|
| 00000110              | 10000000                 |

In this example:

- **Integer Part (00000110)**: Represents `6` in decimal.
- **Fractional Part (10000000)**: Represents `0.5` in decimal.

Thus, the combined fixed-point value represents `6.5`.

### Example Code for Fixed-Point Numbers

The following code shows how to represent fixed-point numbers in C++:

```cpp
#include <iostream>

class FixedPoint {
private:
    int value; // Fixed-point number stored as an integer
    static const int scale = 256; // Scaling factor for fractional part (2^8 = 256)

public:
    FixedPoint(float number) : value(static_cast<int>(number * scale)) {}

    float toFloat() const {
        return static_cast<float>(value) / scale;
    }

    void print() const {
        std::cout << "Fixed-Point Number: " << toFloat() << std::endl;
    }
};

int main() {
    FixedPoint num(6.5); // Represent 6.5 as a fixed-point number
    num.print(); // Output to console
    return 0;
}
```

In this example:

The FixedPoint class stores a float value as an integer in fixed-point format.
The number 6.5 is stored as 6.5 * 256 = 1664, and by dividing by the scaling factor of 256, we get back 6.5.
Fixed-point numbers allow us to perform fractional calculations efficiently, making them advantageous for systems where performance and memory efficiency are critical. However, they are less flexible than floating-point numbers because fractional precision is fixed.

# Floating Point Numbers

Floating-point numbers are a way of representing real numbers in computers. These numbers are used when you need to handle very large or very small values. They are represented in a format similar to scientific notation and are particularly useful for working with decimal values. The IEEE 754 standard is the most widely used standard for representing floating-point numbers in modern computers.

## Structure of a Floating-Point Number

A floating-point number consists of three main parts:

1. **Sign Bit**: Indicates whether the number is positive or negative.
2. **Exponent**: Determines the magnitude (size) of the number.
3. **Mantissa (or Significand)**: Represents the precision or the fractional part of the number.

The standard floating-point format used is the **IEEE 754** standard, and there are typically two formats:
- **Single Precision (32 bits)**: 1 bit for sign, 8 bits for exponent, and 23 bits for mantissa.
- **Double Precision (64 bits)**: 1 bit for sign, 11 bits for exponent, and 52 bits for mantissa.

### IEEE 754 Single Precision (32-bit)

The structure for **single precision** (32-bit) floating-point numbers is as follows:

| Bit Count       | Component   | Description                                    |
|-----------------|-------------|------------------------------------------------|
| 1 bit           | Sign Bit    | Indicates whether the number is positive (0) or negative (1). |
| 8 bits          | Exponent    | Encodes the exponent, which determines the scale or size of the number. |
| 23 bits         | Mantissa    | Encodes the significant digits or precision part of the number. |

### Floating Point Representation

The value of a floating-point number can be calculated using the following formula:

```plaintext
Value = (-1)^Sign × Mantissa × 2^(Exponent - Bias)
```

Where:
- **Sign**: 0 for positive, 1 for negative.
- **Mantissa**: The precision part of the number.
- **Exponent**: Determines the scaling of the number.
- **Bias**: A shift applied to the exponent to make it always non-negative. (For single precision, the bias is 127, and for double precision, it is 1023).

### Example - IEEE 754 Single Precision

If we have the following components for a 32-bit floating-point number:

- **Sign**: 0 (positive)
- **Exponent**: 10000001 (binary, which equals 129; bias = 127, so exponent = 2)
- **Mantissa**: 1.01 (binary)

The value of the floating-point number is calculated as:

```plaintext
Value = (-1)^0 * 1.25 * 2^2 = 5
```

### Advantages and Disadvantages of Floating-Point Numbers

#### Advantages:
- **Wide Range**: Can represent very large and very small numbers.
- **Precision**: Suitable for calculations involving decimal numbers.

#### Disadvantages:
- **Precision Loss**: Floating-point numbers may introduce small errors due to the finite precision of their representation.
- **Rounding Errors**: Representing an infinite number of decimal values with a finite number of bits can result in rounding errors.

### Floating Point Numbers in Practice

Floating-point numbers are used in various fields, including scientific computing, engineering simulations, graphics processing units (GPUs), sound processing, and physics simulations. These applications often require handling extremely large or small numbers, and floating-point numbers provide the flexibility needed for these tasks.

---

## Differences Between Fixed-Point and Floating-Point Numbers


| Feature               | Fixed-Point Numbers                           | Floating-Point Numbers                       |
|-----------------------|-----------------------------------------------|---------------------------------------------|
| **Precision**          | Fixed precision with a fixed number of decimal places | Higher precision with variable decimal places |
| **Speed**              | Faster, requires less processing power       | Slower, requires more processing power      |
| **Memory Usage**       | Uses less memory                             | Uses more memory due to extra components (mantissa and exponent) |
| **Range**              | Limited range, smaller numbers can be represented | Larger range, can represent very small and very large numbers |
| **Applications**       | Embedded systems, Digital Signal Processing (DSP), game programming | Scientific computing, engineering applications, graphics processing |
| **Flexibility**        | Less flexible, precision is fixed            | More flexible, can scale the number using exponent |



## Operator Overloading in C++

Operator overloading is a feature in C++ that allows developers to define custom behavior for operators (like `+`, `-`, `*`, `==`, etc.) when applied to objects of a class. Instead of using the default implementation of an operator, you can redefine how the operator behaves for user-defined data types, making your code more intuitive and expressive.

### Why Use Operator Overloading?

Operator overloading enhances code readability and allows for the creation of more intuitive classes. It allows you to write expressions that use operators (such as addition or subtraction) on objects, just like you would on primitive data types.

For example, consider a `Complex` class for complex numbers. Without operator overloading, adding two complex numbers might involve a function call like `add(complex1, complex2)`. With operator overloading, you can use the `+` operator directly, making the code cleaner and easier to understand.

### Basic Rules of Operator Overloading

1. **Cannot Overload Certain Operators**: Some operators, like `::`, `sizeof`, `.` (member access operator), `? :` (ternary), and `typeid` cannot be overloaded.
2. **Maintain Operator Arity**: You cannot change the number of operands an operator takes. For example, you cannot make a binary operator behave like a unary operator or vice versa.
3. **Use of Friend Function**: For some operators (like `<<` and `>>`), it is common to declare the operator function as a friend function to allow access to private members of the class. **(NOTE ‼️‼️ But note that the use of friends in pdfs is prohibited ‼️‼️**

### Syntax for Operator Overloading

You can overload operators either as member functions or as non-member (friend) functions.

#### 1. **Overloading Operators as Member Functions**

For unary operators, you typically overload them as member functions. Here's an example with the `-` operator (negation):

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r, int i) : real(r), imag(i) {}

    // Overloading the unary '-' operator as a member function
    Complex operator-() {
        return Complex(-real, -imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(4, 5);
    Complex c2 = -c1;  // Calls the overloaded '-' operator
    c2.display();  // Output: -4 + -5i
    return 0;
}
````

### Types of Operators That Can Be Overloaded

Unary Operators: These operators work on a single operand. Examples include -, ++, --, and !.

```cpp
Complex operator-();   // Unary negation
Complex operator++();  // Unary increment
Binary Operators: These operators work on two operands. Examples include +, -, *, /, and =.
```

```cpp
Complex operator+(const Complex& other);   // Addition
Complex operator-(const Complex& other);   // Subtraction
Complex operator*(const Complex& other);   // Multiplication
Comparison Operators: You can overload comparison operators to allow comparisons between objects. Examples include ==, !=, <, >, <=, and >=.
```

```cpp
bool operator==(const Complex& other);   // Equality comparison
bool operator!=(const Complex& other);   // Inequality comparison
Stream Insertion/Extraction Operators: Overload the << and >> operators to enable easy input and output for user-defined types.
```

```cpp
friend ostream& operator<<(ostream& os, const Complex& c);   // Stream insertion  (NOTE !!!! : But note that the use of friends in pdfs is prohibited !!!!!!)
friend istream& operator>>(istream& is, Complex& c);          // Stream extraction
Example of overloading the << operator:
```

```cpp
friend ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}
// Example usage:
Complex c1(4, 5);
cout << c1;  // Output: 4 + 5i
```



