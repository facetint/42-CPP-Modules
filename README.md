## 42-CPP-Module-01

## Installation

```
git clone -b CPP-Module-01 https://github.com/facetint/42-CPP-Modules.git
```

## Table of Contents
1. [C++ Memory Management](#c-memory-management)
   - [Automatic Memory Management (Stack)](#automatic-memory-management-stack)
   - [Manual Memory Management (Heap)](#manual-memory-management-heap)
   - [Dynamic Array Memory Management](#dynamic-array-memory-management)
2. [References](#references)
   - [Properties of References](#properties-of-references)
   - [References in Functions](#references-in-functions)
     - [Functions with Reference Parameters](#functions-with-reference-parameters)
     - [Const References](#const-references)
     - [Returning Reference from Functions](#returning-reference-from-functions)
3. [Differences between References and Pointers](#differences-between-references-and-pointers)
4. [File Operations](#file-operations)
   - [File Open](#file-open)
   - [File Opening and Closing](#file-opening-and-closing)
   - [Writing to File](#writing-to-file)
   - [Reading from File](#reading-from-file)
   - [File Modes](#file-modes)
5. [Switch Case](#switch-case)
   - [Explanations](#explanations)
   - [Important Points](#important-points)
   - [Advantages of using switch-case](#advantages-of-using-switch-case)

---

## C++ Memory Management

Memory management in C++ gives the programmer a great deal of flexibility and control, but it can also lead to problems such as memory leaks or errors if care is not taken. Memory management can be divided into two main categories: automatic memory management (stack) and manual memory management (heap). Let's examine how these two types of memory work.

### Automatic Memory Management (Stack)

The stack is the automatic allocation of memory. Local variables defined inside functions are automatically added to the stack memory when the function is called, and this memory is automatically freed when the function terminates.

Memory management on the stack is easy because C++ manages this memory automatically. The data in the stack is small and of fixed size; it is usually short-lived. For example, a local variable in a function is on the stack when the function is called and is deleted when the function ends.

### Manual Memory Management (Heap)

Heap is the partition with dynamic memory allocation and memory management is done manually. The new operator is used to allocate memory on the heap, and the delete operator is used to free the allocated memory. Memory allocation on the heap can continue throughout the runtime of the program, and larger data is stored there than on the stack.

The important point here is to release the allocated memory without forgetting it. Otherwise, a memory leak may occur. This means that if memory is not released on the heap, it will run out of memory.

### Dynamic Array Memory Management

It is also possible to create an array on the heap. The dynamic array can be allocated with the new[] operator and freed with the delete[] operator.

---

## References

In C++, references are a powerful feature that allows giving variables an alternative name and working with them directly. A reference is like a pointer to the address of a variable in memory, but it is easier to use and more secure. In C++, references are often used to optimize parameter passing in functions and to provide safer memory management.

### Properties of References

- **Points to the Same Address in Memory**: A reference uses the address in memory of the variable from which it was created, and any changes made to that reference take effect directly on the original variable.
- **Cannot be Reassigned to Another Variable**: Once a reference is assigned to a variable, it cannot be bound to another variable. That is, the reference continues to point to the variable to which it is bound throughout its lifecycle.
- **Cannot be Null**: References, like pointers, cannot take the value `nullptr`; they must always point to a valid variable.

### References in Functions

References are especially useful for function parameters and return values. Normally when a function is called, the parameters are copied and passed. However, this can be costly for large data structures. By using references, instead of copying the data, the original data is accessed directly and performance is improved.

#### Functions with Reference Parameters

Passing parameters to functions using references is ideal for efficiently handling large data structures. This avoids duplication and the original data can be manipulated directly.

#### Const References

If you want to ensure that when passing a reference as a parameter of a function, that reference is not modified, you can use a const reference. This ensures read-only reference passing and increases data security.

#### Returning Reference from Functions

A function can return a reference. However, in this case, it is important that the lifetime of the returned reference does not exceed the lifetime of the function. Otherwise, a dangling reference error will occur.

---

## Differences between References and Pointers

| Feature                         | References                                                                                           | Pointers                                                                                                 |
|---------------------------------|------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------|
| **Nullability**                 | Cannot be null                                                                                       | Can be `nullptr`                                                                                        |
| **Reassignment**                | Cannot be reassigned                                                                                 | Can be reassigned                                                                                       |
| **Memory Management**           | Managed automatically                                                                               | Managed manually (using `new` and `delete`)                                                             |
| **Operator Usage**              | Used like a regular variable                                                                        | Uses `*` (for value) and `&` (for address) operators                                                    |
| **Pointer Arithmetic**          | Arithmetic operations not allowed                                                                   | Supports pointer arithmetic                                                                             |
| **Null Check**                  | Cannot perform null check                                                                           | Can perform null check                                                                                  |
| **Memory Access**               | Provides direct access to the value                                                                 | Provides access to the memory address and allows operations on it                                       |
| **Ease of Use**                 | Safer and easier to use                                                                             | Provides more control and flexibility                                                                   |
| **Binding at Declaration**      | Must be bound to a variable when declared                                                           | Can be `nullptr` and assigned to an address later                                                       |
| **Risk**                        | No risk of memory leaks                                                                             | Risk of memory leaks and errors                                                                         |

---

## File Operations

The fstream library is used to perform file operations in C++. This library provides three basic classes for reading, writing and manipulating files:

- **ifstream (input file stream):** Used for reading data from a file.
- **ofstream (output file stream):** Used for writing data to a file.
- **fstream (file stream):** Used for both read and write operations.

### File Operations with the fstream Library

#### File Open

We can use the fstream, ifstream, or ofstream classes to open files. Various modes can be used when opening files:

- `ios::in`: Opens the file in read mode (ifstream default mode)
- `ios::out`: Opens the file in write mode. Overwrites if the file exists, creates if not (ofstream default mode)
- `ios::app`: Appends to the end of the file.
- `ios::binary`: Opens the file in binary mode.
- `ios::trunc`: Resets a file if it exists, or creates it if it does not.
- `ios::ate`: Positions the pointer at the end of the file after opening the file.

#### File Opening and Closing

- **Opening:** When opening a file, the `open()` function of the file object is called.
- **Closing:** When you are done with the file, you should close it with `close()`.

#### Writing to File

The `ofstream` or `fstream` class is used to write data to the file. Writing is done with the `<<` operator.

#### Reading from File

Reading data from a file is done with the `ifstream` or `fstream` class. Reading can be done with the `>>` operator or the `getline()` function.

#### File Modes

File open modes can be used more than once. For example, for both reading and writing.


```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile("example.txt");  // Open file for writing
    if (outFile.is_open()) {
        outFile << "Hello, world!" << endl;
        outFile.close();
    }

    ifstream inFile("example.txt");   // Open file for reading
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    }

    return 0;
}
```

---

## Switch Case

The switch-case construct allows different blocks of code to be executed based on the value of a variable. This construct is used to check multiple conditions and take action based on a specific state. It is similar to the if-else construct, but offers a cleaner and clearer way of checking multiple states.

### Explanations

- **switch statement**: Starts with a variable (int, char, etc.) to be controlled.
- **case tags**: Tests which constant values the variable being checked is equal to. Each case tag contains a constant value.
- **break statement**: Allows the code to exit the switch structure after exiting that case statement. If break is not used, subsequent case blocks can be executed (this is called “fall-through”).
- **default tag**: Is the block of code that will be executed when no case value is provided. This part is optional.

### Important Points

- **Variable Type:** The variables used in switch-case are usually integer types (int, char, enum). Floating point types like float or double cannot be used.
- **case Constants:** Each case tag represents a constant value. These constants can be numbers or characters, but cannot be variables.
- **break Usage:** The break statement allows to exit the switch structure after completing the code block according to the checked condition. Otherwise, the next case block in the switch structure is also executed.
- **Fall-Through:** When break is not used, all case blocks after a case block are also executed. This is called fall-through.

### Advantages of using switch-case

- Provides a more readable and manageable structure instead of a large number of if-else structures.
- It is generally faster when controlling a large number of cases.
- As a result, the switch-case structure is a convenient and flexible structure for controlling specific states and executing operations conditionally
