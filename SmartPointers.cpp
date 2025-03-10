/*/

Smart pointers in C++ are part of the Standard Library (<memory>) and help manage dynamically allocated memory automatically. 
They prevent memory leaks by ensuring that allocated memory is automatically freed when no longer needed.

Why Use Smart Pointers?
Automatic memory management → No need to manually call delete.
Exception safety → Prevents memory leaks if an exception occurs.
Avoids dangling pointers → Ensures memory is properly deallocated.
Supports RAII (Resource Acquisition Is Initialization).
Prevents double deletions and undefined behavior.

Types of Smart Pointers

std::unique_ptr<T>	Exclusive ownership	0-Refernces	Single ownership of resource
std::shared_ptr<T>	Shared ownership	Reference counted	Multiple shared references to a resource
std::weak_ptr<T>	Non-owning reference	No increase in reference count	Avoid cyclic dependencies

std::unique_ptr – Exclusive Ownership
A unique_ptr manages a resource and deletes it when it goes out of scope.
It cannot be copied, only moved.

std::shared_ptr – Shared Ownership
Allows multiple shared pointers to manage the same resource.
Keeps track of reference count.
Deletes the resource only when the last shared_ptr is destroyed.

std::weak_ptr – Avoid Cyclic Dependencies
weak_ptr is a non-owning reference to a shared_ptr object.
It does not increase the reference count.
Used to break cyclic references in circular dependencies.

*/

#include <iostream>
#include <memory>

class Resource
{
public:
    Resource() {std::cout << "Resource acquired \n";}
    ~Resource() {std::cout << "Resource released \n";}
    void sayHello() {std::cout << "Hello from Resources \n";}
};

class B; //Forward Declaration

class A
{
public:
    std::shared_ptr<B> bPtr; //Strong Reference
    ~A() {std::cout << "A destroyed \n";}
};

class B
{
public:
    std::weak_ptr<A> aPtr; // Weak reference avoids cyclic dependency
    ~B() {std::cout << "B destroyed \n";}
};

void useUniquePtr()
{
    std::unique_ptr<Resource> ptr = std::make_unique<Resource>();
    ptr->sayHello();
}

int main()
{
    useUniquePtr();

    std::shared_ptr<Resource> sp1 = std::make_shared<Resource>();
    std::shared_ptr<Resource> sp2 = sp1;

    std::cout << "Reference count: "<<sp1.use_count() << std::endl;

    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->bPtr = b;
    b->aPtr = a;

    return 0;
}