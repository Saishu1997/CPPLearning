#include <iostream>
#include <memory>

class Car
{
public:
    Car() { std::cout << "Car Created \n"; }
    ~Car() { std::cout << "Car Destroyed \n"; }
};

int main()
{
    std::shared_ptr<Car> sp1 = std::make_shared<Car>();
    std::cout << "Reference Count: " << sp1.use_count() << "\n";
    {
        std::shared_ptr<Car> sp2 = sp1;
        std::cout << "Reference Count: " << sp1.use_count() << "\n";

        std::shared_ptr<Car> sp3 = sp2;
        std::cout << "Reference Count: " << sp1.use_count() << "\n";
    }

    std::cout << "Reference Count: " << sp1.use_count() << "\n";
}