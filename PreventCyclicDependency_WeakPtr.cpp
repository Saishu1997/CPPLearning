#include <iostream>
#include <memory>

class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> bPtr;  // Strong reference
    A() { std::cout << "A Created\n"; }
    ~A() { std::cout << "A Destroyed\n"; }
};

class B {
public:
    std::weak_ptr<A> aPtr;  // ✅ Weak reference to prevent cycle
    B() { std::cout << "B Created\n"; }
    ~B() { std::cout << "B Destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->bPtr = b;
    b->aPtr = a;  // ✅ Prevents cyclic reference

    return 0;
}