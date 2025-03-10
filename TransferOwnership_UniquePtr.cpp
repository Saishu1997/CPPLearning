#include <iostream>
#include <memory>
#include <string>

class Person
{
public:
    std::string name;
    int age;

    Person(std::string n, int a) : name(n), age(a)
    {
        std::cout << "Person Created:" << name << ", Age" << age << "\n";
    }

    ~Person()
    {
        std::cout << "Person Destroyed \n";
    }
};

void displayPerson(std::unique_ptr<Person> p)
{
    std::cout << "Person Transferred to Function \n";
}

int main()
{
    std::unique_ptr<Person> person = std::make_unique<Person>("John", 25);
    displayPerson(std::move(person));
}