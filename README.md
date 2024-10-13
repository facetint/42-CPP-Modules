# 42-CPP-Modules


## C++ Memory Management

It is about how the program allocates and manages memory. Memory management in C++ gives the programmer a great deal of flexibility and control, but it can also lead to problems such as memory leaks or errors if care is not taken. Memory management can be divided into two main categories: automatic memory management (stack) and manual memory management (heap). Let's examine how these two types of memory work.

**1. Automatic Memory Management (Stack)**
The stack is the automatic allocation of memory. Local variables defined inside functions are automatically added to the stack memory when the function is called, and this memory is automatically freed when the function terminates.

Memory management on the stack is easy because C++ manages this memory automatically. The data in the stack is small and of fixed size; it is usually short-lived. For example, a local variable in a function is on the stack when the function is called and is deleted when the function ends.


**2. Manual Memory Management (Heap)**

Heap is the partition with dynamic memory allocation and memory management is done manually. The new operator is used to allocate memory on the heap, and the delete operator is used to free the allocated memory. Memory allocation on the heap can continue throughout the runtime of the program, and larger data is stored there than on the stack.
The important point here is to release the allocated memory without forgetting it. Otherwise a memory leak may occur. This means that if memory is not released on the heap, it will run out of memory.

**3. Dynamic Array Memory Management**

It is also possible to create an array on the heap. The dynamic array can be allocated with the new[] operator and freed with the delete[] operator.

