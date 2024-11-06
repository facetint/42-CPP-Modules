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


# POLIMORFIZM

Polymorphism in C++ refers to the ability of objects to take on multiple forms according to their context or use. The same entity (method or object) behaves differently in different scenarios.
Like real-life scenarios where a person can exhibit various roles simultaneously, such as being a parent, spouse, and employee, C++ Polymorphism enables objects to exhibit different behaviors depending on the situation.


## Types of Polymorphism

<img width="824" alt="Ekran Resmi 2024-11-06 17 45 11" src="https://github.com/user-attachments/assets/b8ea2118-05cc-4649-b3ed-8282d3887056">

## 1. Compile Time Polymorphism

Compile-time Polymorphism refers to the mechanism in C++ where the compiler determines which function to call during compilation based on the function’s signature and the context in which it is invoked. This is typically achieved through function overloading and operator overloading.

### A. Function Overloading

Function overloading occurs when multiple functions have the same name but different parameters. This enables the same function name to perform various tasks based on the parameters provided, which can vary in number or type. It’s a feature of object-oriented programming that allows for creating multiple functions with the same name but different parameter lists.

### B. Operator Overloading

In C++, operator overloading empowers operators to have special meanings for specific data types. For instance, we can redefine the addition operator (+) for the string class to concatenate two strings. This flexibility allows us to extend the functionality of operators beyond their conventional usage.

## 2. Runtime Polymorphism

Runtime Polymorphism in C++, also known as late binding or dynamic Polymorphism, is achieved through function overriding. Unlike compile-time Polymorphism, where the function call is resolved at compile time, run time Polymorphism in C++ resolves the function call at runtime. This allows for greater flexibility as the specific function implementation is determined based on the actual object type during program execution.

### A. Function overriding
Function overriding occurs when a derived class provides a specific implementation for a function already defined in its base class. This allows objects of the derived class to use their version of the function, providing a way to achieve runtime Polymorphism.

### B. Virtual Function

A virtual function is a member function declared within a base class that is redefined (or overridden) in a derived class. It allows the derived class to provide its implementation of the function, which is invoked based on the actual object type during runtime.

This enables runtime Polymorphism, where the appropriate function implementation is selected dynamically based on the object’s type rather than statically at compile time.

**Key Points To Remember:***

Virtual functions are declared using the virtual keyword in the base class.
They are overridden in derived classes using the override keyword.
Virtual functions enable dynamic binding, where the call is resolved at runtime.
They allow for polymorphic behavior, where objects of different derived classes can be treated uniformly through a standard interface.

| Özellik                      | Derleme Zamanı Polimorfizmi                                                                                         | Çalışma Zamanı Polimorfizmi                                                                                           |
|------------------------------|----------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------|
| **Tanım**                    | Derleme zamanı C++'daki polimorfizm, hangi fonksiyon veya işlemin çağrılacağını, argümanların sayısına, türlerine ve sırasına göre belirler. | Hangi fonksiyonun çağrılacağına dair karar, referans veya işaretçi türünden ziyade gerçek nesne türüne göre çalışma zamanında belirlenir. |
| **Bağlayıcı**                | Statik bağlama, fonksiyon çağrılarının tanımlarına statik olarak bağlanmasıdır.                                      | Dinamik bağlama, fonksiyon çağrılarının tanımlarına dinamik olarak bağlanmasıdır.                                       |
| **Polimorfizm Türü**         | Statik veya erken bağlama Polimorfizmi olarak da bilinir.                                                            | Geç bağlama veya dinamik Polimorfizm olarak da bilinir.                                                                 |
| **Fonksiyon Aşırı Yüklemesi** | Birden fazla fonksiyon aynı ada sahiptir ancak farklı parametreler tanımlanmıştır. Derleyici, hangi fonksiyonun çağrılacağını argümanların sayısına ve türlerine göre belirler. | Uygulanamaz.                                                                                                           |
| **Operatör Aşırı Yüklemesi** | Operatörler, işlenen türlerine bağlı olarak farklı işlemler gerçekleştirmek üzere aşırı yüklenebilir.               | Uygulanamaz.                                                                                                           |
| **Miras**                    | Dahil değil.                                                                                                        | Kalıtım içerir; burada türetilmiş sınıf, temel sınıfından gelen bir fonksiyonu geçersiz kılar.                          |
| **Uygulama Hızı**            | Derleyici, derleme zamanında hangi fonksiyonun çağrılacağını belirlediğinden daha hızlı yürütme hızı.               | Hangi fonksiyonun çağrılacağına çalışma zamanında karar verildiği için yürütme hızı nispeten daha yavaştır.             |
| **Kod Yeniden Kullanılabilirliği** | Aynı fonksiyon adı farklı parametrelerle kullanılabildiği için yüksek kod yeniden kullanılabilirliği sağlar. | Aynı fonksiyon adı farklı nesne tipleriyle kullanılabildiği için yüksek kod yeniden kullanılabilirliği sağlar.         |
| **C++'da Polimorfizm**       | Operatör aşırı yüklenmesi ve fonksiyon aşırı yüklenmesiyle elde edilir.                                            | Fonksiyon geçersiz kılma yoluyla elde edilir.                                                                          |


# Pure Virtual Functions and Abstract Classes in C++

## Abstract Class in C++

In C++, an abstract class is defined by having at least one pure virtual function, a function without a concrete definition. These classes are essential in object-oriented programming, structuring code to mirror real-life scenarios through inheritance and abstraction. Abstract classes, which cannot be instantiated, are pivotal for expressing broad concepts and upcasting, allowing derived classes to implement their interfaces. Utilize pointers and references for abstract class types, and remember that any subclass failing to define the pure virtual function becomes abstract itself. The virtual function is declared with the pure specifier (= 0).

### Restrictions on Abstract Classes

There are some restrictions on abstract classes in C++.

Abstract classes cannot be used for the following –

Variables or member data
Argument types
Function return types
Types of explicit conversions.
The constructors of the abstract class in c++ can call other member functions, but if they directly or indirectly call the pure virtual function, then the result is undefined.

A virtual function in C++ is a member function declared within a base class and redefined by the derived class.

A pure virtual function (or abstract function) is a virtual function with no definition/logic. It is declared by assigning 0 at the time of declaration.

### Characteristics of Abstract Class in C++

**1- Abstract Classes must have at least one pure virtual function.**

```c++
virtual int perimeter() = 0;
````

**2-Abstract Classes cannot be instantiated, but pointers and references of Abstract Class types can be created. You cannot create an object of an abstract class. Here is an example of a pointer to an abstract class.**


```c++

#include<iostream>
using namespace std;

class Base {
  public:
    virtual void print() = 0;
};

class Derived: public Base {
  public: 
    void print() {
      cout << "This is from the derived class \n";
    }
};

int main(void) {
  Base* basePointer = new Derived();
  basePointer -> print();
  return 0;
}
````

Output –

```c++

This is from the derived class
````

**3- Abstract Classes are mainly used for Upcasting, which means its derived classes can use its interface.**
**4- Classes that inherit the Abstract Class must implement all pure virtual functions. If they do not, those classes will also be treated as abstract classes.**

#### Why Can’t We Make an Abstract Class Object?

Abstract classes in C++ cannot be instantiated because they are “abstract”. It’s like someone is telling you to draw an animal without telling you which specific animal. You can only draw if the person asks you to draw a cat, dog, etc., but an animal is abstract.

The same is the case with abstract classes in C++, so we can’t create objects, but we can create a pointer of an abstract class.
