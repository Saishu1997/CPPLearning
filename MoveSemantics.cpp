/*

In traditional C++, objects are copied when assigned or passed to a function, 
which can be expensive, especially for large objects (like vectors, strings, or file streams). 
Move semantics allows transferring ownership of resources instead of copying them.

2. Lvalues vs Rvalues
Understanding move semantics starts with distinguishing lvalues and rvalues:

Lvalues (Left Values):

Have a name and persist beyond a single expression.
Can be assigned to (modifiable).
Example:
cpp
Copy
Edit
int x = 10;  // x is an lvalue
x = 20;      // Valid, as x persists
Rvalues (Right Values):

Temporary values that do not persist beyond the expression.
Cannot be assigned to (unless bound to an rvalue reference).
Example:
cpp
Copy
Edit
int y = x + 5;  // (x + 5) is an rvalue, as it has no memory address
3. Rvalue References (&&)
C++11 introduced rvalue references (&&), which allow us to "steal" resources from temporary objects instead of copying them.

Lvalue reference (&) binds only to lvalues:

cpp
Copy
Edit
int a = 10;
int& ref = a;   // Okay: ref binds to lvalue a
int& ref2 = 5;  // ❌ Error: 5 is an rvalue
Rvalue reference (&&) binds only to rvalues:

cpp
Copy
Edit
int&& ref3 = 5;  // ✅ Okay: ref3 binds to rvalue 5
int&& ref4 = a;  // ❌ Error: a is an lvalue
4. std::move – Converting an Lvalue to an Rvalue
Since rvalue references only bind to temporary objects, how can we move a named (lvalue) object?
👉 std::move(obj) converts an lvalue into an rvalue, allowing it to be moved instead of copied.

5. Move Constructor & Move Assignment Operator
When move semantics is implemented in a class, the compiler uses:

Move Constructor → Moves resources from a temporary object (instead of copying).
Move Assignment Operator → Moves resources in assignment.

The Move Constructor works when we create a new object from a temporary object 
(MoveExample obj2 = std::move(obj1);).
But what if we assign an existing object instead of initializing a new one?
This is where the Move Assignment Operator (operator=) comes in.

*/

#include <iostream>
#include <vector>

class MoveExample
{
private:
    int *data;

public:
    // Constructor
    MoveExample(int value)
    {
        data = new int(value);
        std::cout << "Constructor: Allocated" << *data << "\n";
    }

    // Copy Constructor (Deep Copy)
    MoveExample(MoveExample&& other) noexcept
    {
        data = other.data;
        other.data = nullptr;
        std::cout << "Move Constructor: Moced resource \n";
    }

    // Move Assignment Operator
    MoveExample& operator = (MoveExample&& other) noexcept
    {
        std::cout << "Move Assignment: Moving resource \n";

        // 1. Self assignment check
        if (this == &other) return *this;

        // 2. Free existing resource
        delete data;

        // 3. Transfer ownership
        data = other.data;
        other.data = nullptr;

        return *this;
    }

    // Destructor
    ~MoveExample()
    {
        if (data)
        {
            std::cout << "Destructor Deleted " << *data << "\n";
        }

        else
        {
            std::cout << "Destructor: No resource to delete \n";
        }
        delete data;
    }
};

int main()
{
    MoveExample obj1(42);
    MoveExample obj2(99);
    obj2 = std::move(obj1);

    return 0;
}