#include <iostream>
#include <utility>  // For std::move

class Example {
private:
    int* ptr;  // Dynamic memory to illustrate deep/move copy

public:
    /*** 1. DEFAULT CONSTRUCTOR ***/
    // Initializes the object with a default value
    Example() : ptr(new int(0)) {  
        std::cout << "Default Constructor: Initialized with 0\n";
    }

    /*** 2. PARAMETERIZED CONSTRUCTOR ***/
    // Allows initialization with a specific value
    Example(int v) : ptr(new int(v)) {  
        std::cout << "Parameterized Constructor: Initialized with " << *ptr << "\n";
    }

    /*** 3. COPY CONSTRUCTOR (Deep Copy) ***/
    // Copies an existing object (allocates new memory to prevent shallow copy issues)
    Example(const Example& other) {
        ptr = new int(*other.ptr);  // Deep copy
        std::cout << "Copy Constructor: Copied value " << *ptr << "\n";
    }

    /*** 4. MOVE CONSTRUCTOR ***/
    // Moves an object instead of copying it (steals the resource)
    Example(Example&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;  // Nullify the old object's pointer
        std::cout << "Move Constructor: Moved resource\n";
    }

    /*** 5. COPY ASSIGNMENT OPERATOR ***/
    // Assigns one existing object to another (Deep Copy)
    Example& operator=(const Example& other) {
        if (this == &other) return *this;  // Self-assignment check

        delete ptr;  // Free old memory
        ptr = new int(*other.ptr);  // Allocate new memory and copy
        std::cout << "Copy Assignment: Copied value " << *ptr << "\n";
        return *this;
    }

    /*** 6. MOVE ASSIGNMENT OPERATOR ***/
    // Moves an object instead of copying it
    Example& operator=(Example&& other) noexcept {
        if (this == &other) return *this;  // Self-assignment check

        delete ptr;  // Free old resource
        ptr = other.ptr;  // Take ownership of the resource
        other.ptr = nullptr;  // Nullify old object's pointer
        std::cout << "Move Assignment: Moved resource\n";
        return *this;
    }

    /*** 7. DELEGATING CONSTRUCTOR ***/
    // Calls another constructor to avoid redundant code
    Example(bool flag) : Example(flag ? 100 : 50) {
        std::cout << "Delegating Constructor: Called another constructor\n";
    }

    /*** 8. EXPLICIT CONSTRUCTOR ***/
    // Prevents implicit conversions
    explicit Example(double v) : ptr(new int(static_cast<int>(v))) {  
        std::cout << "Explicit Constructor: Initialized with " << *ptr << "\n";
    }

    /*** Destructor ***/
    // Frees allocated memory
    ~Example() {
        delete ptr;  
        std::cout << "Destructor: Released memory\n";
    }

    /*** Helper Method to Display Value ***/
    void display() const {
        if (ptr)
            std::cout << "Value: " << *ptr << "\n";
        else
            std::cout << "Object is empty (moved)\n";
    }
};

int main() {
    std::cout << "\n1. Default Constructor:\n";
    Example obj1;  // Calls Default Constructor

    std::cout << "\n2. Parameterized Constructor:\n";
    Example obj2(42);  // Calls Parameterized Constructor

    std::cout << "\n3. Copy Constructor:\n";
    Example obj3 = obj2;  // Calls Copy Constructor

    std::cout << "\n4. Move Constructor:\n";
    Example obj4 = std::move(obj2);  // Calls Move Constructor

    std::cout << "\n5. Copy Assignment Operator:\n";
    Example obj5;
    obj5 = obj3;  // Calls Copy Assignment Operator

    std::cout << "\n6. Move Assignment Operator:\n";
    Example obj6;
    obj6 = std::move(obj3);  // Calls Move Assignment Operator

    std::cout << "\n7. Delegating Constructor:\n";
    Example obj7(true);  // Calls Delegating Constructor

    std::cout << "\n8. Explicit Constructor:\n";
    Example obj8 = Example(3.14);  // Calls Explicit Constructor

    std::cout << "\nDisplaying Values:\n";
    obj1.display();
    obj2.display();  // Moved, should be empty
    obj3.display();  // Moved, should be empty
    obj4.display();
    obj5.display();
    obj6.display();
    obj7.display();
    obj8.display();

    std::cout << "\nExiting main, destructors will be called...\n";
    return 0;
}