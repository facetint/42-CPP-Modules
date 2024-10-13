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

## References


In C++, references are a powerful feature that allows giving variables an alternative name and working with them directly. A reference is like a pointer to the address of a variable in memory, but it is easier to use and more secure. In C++, references are often used to optimize parameter passing in functions and to provide safer memory management.

**Properties of References**

Points to the Same Address in Memory: A reference uses the address in memory of the variable from which it was created, and any changes made to that reference take effect directly on the original variable.
Cannot be Reassigned to Another Variable: Once a reference is assigned to a variable, it cannot be bound to another variable. That is, the reference continues to point to the variable to which it is bound throughout its lifecycle.
Cannot be Null: References, like pointers, cannot take the value nullptr; they must always point to a valid variable.
Reference Definition
A reference is defined to give a variable an alternative name. To define a reference, the & symbol is used after the data type.

###References in Functions

References are especially useful for function parameters and return values. Normally when a function is called, the parameters are copied and passed. However, this can be costly for large data structures. By using references, instead of copying the data, the original data is accessed directly and performance is improved.

**1. Functions with Reference Parameters**
Passing parameters to functions using references is ideal for efficiently handling large data structures. This avoids duplication and the original data can be manipulated directly.

**2. Const References**

If you want to ensure that when passing a reference as a parameter of a function, that reference is not modified, you can use a const reference. This ensures read-only reference passing and increases data security.

**3. Returning Reference from Functions**

A function can return a reference. However, in this case, it is important that the lifetime of the returned reference does not exceed the lifetime of the function. Otherwise a dangling reference error will occur.

## Differences between References and Pointers



| **Özellik**                  | **Referanslar (References)**                          | **Göstericiler (Pointers)**                            |
|------------------------------|-------------------------------------------------------|-------------------------------------------------------|
| **Null olma durumu**          | `null` olamaz                                         | `nullptr` olabilir                                    |
| **Yeniden atama**             | Yeniden atanamaz                                      | Yeniden atanabilir                                    |
| **Bellek yönetimi**           | Otomatik olarak yapılır                               | Manuel olarak yapılır (`new` ve `delete` ile)         |
| **İşlem operatörleri**        | Normal değişken gibi kullanılır                       | `*` (değer), `&` (adres) operatörleri kullanılır      |
| **Pointer aritmetiği**        | Aritmetik işlemler yapılamaz                          | Pointer aritmetiği kullanılabilir                     |
| **Null kontrolü**             | Null kontrolü yapılamaz                               | Null kontrolü yapılabilir                             |
| **Bellek adresine erişim**    | Doğrudan değere erişim sağlar                         | Bellek adresine erişim sağlar ve adres üzerinden işlem yapılır |
| **Kullanım zorluğu**          | Daha güvenli ve kolay                                | Daha fazla kontrol ve esneklik sağlar                 |
| **Tanımlama esnasında bağlanma** | Tanımlandığı anda bir değişkene bağlanmak zorundadır | Null olabilir ve sonradan bir adrese atanabilir       |
| **Riski**                     | Bellek sızıntısı riski yok                            | Bellek sızıntısı ve hatalar oluşabilir                |


