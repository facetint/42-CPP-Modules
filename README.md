## 42-CPP-Module-05

## Installation

```
git clone -b CPP-Module-05 https://github.com/facetint/42-CPP-Modules.git
```


# 🚨 C++ `try-catch` Mechanism – Mastering Exception Handling

In C++, the `try-catch` mechanism is the primary structure for detecting and handling runtime errors. It provides a clean, structured way to prevent crashes and handle unexpected behaviors. This guide dives into the `try-catch` mechanism from basics to best practices, enriched with diagrams and practical code samples.

---

## 📘 Table of Contents

- [🔧 Basic Concepts](#-basic-concepts)
- [💥 The `throw` Keyword](#-the-throw-keyword)
- [🧲 `try-catch` Structure](#-try-catch-structure)
- [🪄 Multiple `catch` Blocks & Exception Types](#-multiple-catch-blocks--exception-types)
- [🧵 Standard Exception Hierarchy](#-standard-exception-hierarchy)
- [📊 Visualizing `try-catch`](#-visualizing-try-catch)
- [🧪 Real-World Example](#-real-world-example)
- [🔚 Conclusion & Tips](#-conclusion--tips)

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

<img width="542" alt="Ekran Resmi 2025-05-03 00 04 33" src="https://github.com/user-attachments/assets/ee22688a-342c-4390-a94b-6900db2d4150" />



💥 The throw Keyword
You use throw to signal that something has gone wrong.

```
void divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Division by zero!");
    std::cout << a / b << std::endl;
}

```

🧲 try-catch Structure


```
try {
    divide(10, 0);
} catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << std::endl;
}

```

try block: Contains code that might cause an exception.

catch block: Catches exceptions of a specific type.


🪄 Multiple catch Blocks & Exception Types

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

