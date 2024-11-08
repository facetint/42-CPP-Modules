# 42-CPP-Modules

| Module              | GitHub Link                                                |
|---------------------|-----------------------------------------------------------|
| CPP-Modules-00      | [CPP-Modules-00](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-00) |
| CPP-Modules-01      | [CPP-Modules-01](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-01) |
| CPP-Modules-02      | [CPP-Modules-02](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-02) |
| CPP-Modules-03      | [CPP-Modules-03](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-03) |
| CPP-Modules-04      | [CPP-Modules-04](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-04) |
| CPP-Modules-05      | [CPP-Modules-05](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-05) |
| CPP-Modules-06      | [CPP-Modules-06](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-06) |
| CPP-Modules-07      | [CPP-Modules-07](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-07) |
| CPP-Modules-08      | [CPP-Modules-08](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-08) |
| CPP-Modules-09      | [CPP-Modules-09](https://github.com/facetint/42-CPP-Modules/tree/CPP-Module-09) |



## The Orthodox Canonical Class Form

- A default constructor: used internally to initialize objects and data members when no other value is available.

- A copy constructor: used in the implementation of call-by-value parameters.

- An assignment operator: used to assign one value to another.

- A destructor: Invoked when an object is deleted.


The purpose of this form is to prevent memory leaks, copy errors and unnecessary copies in classes that require resource management. For example, if a class dynamically allocates memory, it needs to perform this memory management properly when copied or moved. If these special member functions are not defined, C++ automatically provides a copy constructor and copy assignment operator by default, but this does not guarantee that resources are managed correctly, which can lead to memory leaks or unexpected behavior.


## Fixed-Point Numbers

### What is a Fixed-Point Number?

A fixed-point number is a method of representing numerical values where the number of decimal places is fixed. Fixed-point numbers are particularly useful in embedded systems or applications requiring high performance and limited memory because they allow fractional numbers to be represented with a fixed number of decimal points.

In fixed-point notation, part of the number is the integer part and the other part is the fractional part. This allows fractional values to be represented similarly to floating-point numbers, but with a fixed number of decimal places.

### Key Features of Fixed-Point Numbers

Fixed Decimal Point: Unlike floating-point numbers, the decimal point in fixed-point numbers remains in a fixed position. For example, the last 8 bits can represent the fractional part. Thus, the number 123.45 can be stored as 12345, and we know the location of the decimal point.

#### Precision and Scaling: 
Fixed-point numbers are stored as integers and scaled by a fixed factor. For example, if we scale by 256, the number 1.5 is stored as 384, and 384 / 256 = 1.5.

Difference from Floating-Point Numbers: Fixed-point numbers have fixed precision with a limited number of decimal places, making them faster but less flexible than floating-point numbers.

### Use Cases of Fixed-Point Numbers
Fixed-point representation is widely used in embedded systems, game programming, and digital signal processing (DSP), where limited hardware resources must handle fractional number calculations efficiently.

### Fixed-Point Representation Example

In an 8.8 fixed-point representation, the first 8 bits represent the integer part, and the last 8 bits represent the fractional part.

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


