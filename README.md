## 42-CPP-Module-05

## Installation

```
git clone -b CPP-Module-05 https://github.com/facetint/42-CPP-Modules.git
```

## 📘 Table of Contents

- [🚨 C++ `try-catch` Mechanism](#-c-try-catch-mechanism)
- [🔧 Basic Concepts](#-basic-concepts)
- [💥 The `throw` Keyword](#-the-throw-keyword)
- [🧲 `try-catch` Structure](#-try-catch-structure)
- [🪄 Multiple `catch` Blocks & Exception Types](#-multiple-catch-blocks--exception-types)
- [🧵 Standard Exception Hierarchy](#-standard-exception-hierarchy)
- [🧰 Defining Custom Exceptions in C++](#-defining-custom-exceptions-in-c)
- [🔚 Conclusion & Best Practices](#-conclusion--best-practices)
- [📎 Recommended Resources](#-recommended-resources)

---

# 🚨 C++ `try-catch` Mechanism

In C++, the `try-catch` mechanism is the primary structure for detecting and handling runtime errors. It provides a clean, structured way to prevent crashes and handle unexpected behaviors. This guide dives into the `try-catch` mechanism from basics to best practices, enriched with diagrams and practical code samples.

---

## 🔧 Basic Concepts

In C++, when an error occurs (e.g., invalid input, file not found, memory allocation failure), the program can throw an exception instead of crashing.


```cpp
try {
    // Code that might throw an exception
} catch (exception_type e) {
    // Code to handle the exception
}
```




![try-catch structure visualization](https://github.com/user-attachments/assets/ee22688a-342c-4390-a94b-6900db2d4150)




## 💥 The throw Keyword


You use throw to signal that something has gone wrong.

```
void divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division by zero!");
    std::cout << a / b << std::endl;
}

```


## 🧲 try-catch Structure


```
try {
    divide(10, 0);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

```

try block: Contains code that might cause an exception.

catch block: Catches exceptions of a specific type.



## 🪄 Multiple catch Blocks & Exception Types

```
try {
    // some risky code
} catch (const std::out_of_range& e) {
    std::cerr << "Out of range: " << e.what() << std::endl;
} catch (const std::invalid_argument& e) {
    std::cerr << "Invalid argument: " << e.what() << std::endl;
} catch (...) {
    std::cerr << "An unknown error occurred." << std::endl;
}
catch (...): Catches all exceptions (fallback case).

```



## 🧵 Standard Exception Hierarchy


Below is a simplified hierarchy of standard C++ exceptions, showing the inheritance structure and purpose of each exception type:


| 🔗 **Exception Class**        | 🧬 **Inheritance**         | 📋 **Description**                                      |
|------------------------------|----------------------------|---------------------------------------------------------|
| `std::exception`             | —                          | Base class for all standard exceptions                  |
| ├── `std::logic_error`       | `std::exception`           | Errors in program logic (e.g., preconditions violated)  |
| │   ├── `std::invalid_argument` | `std::logic_error`      | Function received invalid argument                      |
| │   ├── `std::out_of_range`  | `std::logic_error`         | Access outside valid range (e.g., vector index)         |
| └── `std::runtime_error`     | `std::exception`           | Errors that happen during program execution             |
|     ├── `std::range_error`   | `std::runtime_error`       | Value out of allowed range (but not index-related)      |
|     ├── `std::overflow_error`| `std::runtime_error`       | Arithmetic overflow occurred                            |
|     ├── `std::underflow_error`| `std::runtime_error`      | Arithmetic underflow occurred                           |
|     └── `std::ios_base::failure` | `std::runtime_error`   | Input/output operation failed                           |
| `std::bad_alloc`             | `std::exception`           | Memory allocation failure (e.g., `new` fails)           |



> 🧠 **Tip:** Always catch exceptions by reference (e.g., `const std::exception&`) to avoid slicing and ensure polymorphic behavior.


## 🧰 Defining Custom Exceptions in C++

The C++ Standard Library provides a rich set of exception classes like `std::runtime_error` and `std::invalid_argument`. However, in real-world projects, these may not always be descriptive or specific enough for your application’s domain.

### ✅ Why Create Custom Exceptions?

Creating your own exception classes allows you to:

- Provide **more meaningful error messages**
- Handle **specific error types** using dedicated `catch` blocks
- Organize your error handling in a **clean, object-oriented way**
- Extend with custom data (e.g., error codes, file names)


```cpp
class MyCustomException : public std::exception {
public:
    const char* what() const throw() {
        return "A custom error occurred!";
    }
};

```


### 💡 Key Points

- `std::exception` is the base class for all standard exceptions.

- We override the `what()` method to return a meaningful error message.

- You can use a `std::string` member to store dynamic error content.

---



## 🔚 Conclusion & Best Practices


Exception handling in C++ allows you to write robust and maintainable programs by cleanly separating error-handling code from regular logic. Here's a summary of best practices:

✅ **Separate concerns**: Use exceptions to handle errors, not control flow. Keep your business logic clean and focused.  

✅ **Catch specific exceptions first**: Always handle known exception types before falling back to a generic `catch (...)`.  

✅ **Use `const` references in catch blocks**: Prevent object slicing and maintain polymorphism using `catch (const std::exception& e)`.  

✅ **Avoid throwing from destructors**: Doing so can lead to undefined behavior if another exception is already active.  

✅ **Create custom exceptions**: When standard exceptions don't convey enough meaning, define your own.



## 📎 Recommended Resources

- 📚 [cppreference.com – Exception Handling](https://en.cppreference.com/w/cpp/language/try_catch)  
  Comprehensive and up-to-date reference for C++ exception syntax and semantics.

- 📘 *The C++ Programming Language* by **Bjarne Stroustrup**  
  A foundational text by the creator of C++, covering exception safety and best practices in depth.

- 💡 [GeeksForGeeks: Exception Handling in C++](https://www.geeksforgeeks.org/exception-handling-c/)  
  Beginner-friendly explanations with code examples and diagrams.



