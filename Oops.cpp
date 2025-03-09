#include <iostream>
#include <vector>

/* 
Encapsulation is the bundling of data (variables) and methods (functions) into a single unit (class) 
while restricting direct access to some of the object's details. This is usually achieved using private/protected access specifiers.

Inheritance allows a class to derive properties and behaviors from another class. The base class provides common functionality, 
while the derived classes extend or modify it.

Polymorphism allows objects to be treated as instances of their base type while calling the correct overridden function in the derived class.

Abstraction is the process of exposing only the necessary details while hiding the implementation.



The virtual keyword allows function calls to be resolved at runtime rather than compile time.
override	Ensures correct function overriding	
protected	Allows derived class access but not outside access
static_cast<>	Converts base class pointer to derived class pointer
auto	Deduces variable type automatically
new/delete	Manages dynamic memory
virtual destructor	Ensures proper cleanup of derived objects

*/

// Base Abstract class (Abstraction)
class GameCharacter
{
protected:
    std::string name;
    int health;
    int attackPower;

public:
    GameCharacter(std::string n, int h, int ap) : name(n), health(h), attackPower(ap) {}

    virtual void attack() = 0; // Pure Virtual Function (Abstraction)

    void TakeDamage(int damage)
    {
        health -= damage;
        std::cout<< name << "takes" << damage << "damage. Health" << health << std::endl;
    }

    virtual ~GameCharacter() {} // Virtual Destructor
};

// Derived class 1: Warrior (Inheritance & Polymorphism)
class Warrior : public GameCharacter
{
private:
    int armor; // Encapsulation

public:
    Warrior(std::string n, int h, int ap, int ar) : GameCharacter(n, h, ap), armor(ar) {}

    void attack() override // Polymorphism
    {
        std::cout << name << "swings a sword! Deals" << attackPower << "damage" << std::endl;
    }

    void block()
    {
        std::cout << name << "blocks an attack, reducing damage by" << armor << std::endl;
    }
};

// Derived class 2: Mage (Inheritance & Polymorphism)
class Mage : public GameCharacter
{
private:
    int mana; // Encapsulation

public:
    Mage(std::string n, int h, int ap, int m) : GameCharacter(n, h, ap), mana(m) {}

    void attack() override // Polymorphism
    {
        std::cout << name << "casts a fireball spell! Deals" << attackPower << "damage" << std::endl;
        mana -= 10;
    }

    void regenerateMana()
    {
        mana += 20;
        std::cout << name << "regenerates mana. Current mana: "<< mana << std::endl;            
    }
};

//Derived class 3: Archer (Inheritance & Polymorphism)
class Archer : public GameCharacter
{
private:
    int arrows; // Encapsulation

public:
    Archer(std::string n, int h, int ap, int a) : GameCharacter(n, h, ap), arrows(a) {}

    void attack() override // Polymorphism
    {
        if (arrows > 0)
        {
            std::cout << name << "shoots an arrow! Deals" << attackPower << "damage" << std::endl;
            arrows--;
        }
        else
        {
            std::cout << name << "is out of arrows" << std::endl;
        }
    }

    void refillArrows()
    {
        arrows += 5;
        std::cout << name << "refills arrows. Current arrows: " << arrows << std::endl;
    }
};

// Gameplay: Characters Interacting
int main()
{
    // Creating objects: Polymorphism
    std::vector<GameCharacter*> characters;
    characters.push_back(new Warrior("Thors", 100, 20, 5));
    characters.push_back(new Mage("Merlin", 80, 30, 50));
    characters.push_back(new Archer("Legolas", 90, 25, 10));

    // Simulating attacks
    for (auto character : characters)
    {
        character->attack();
    }

    // Unique Abilities
    static_cast<Mage*>(characters[1])->regenerateMana();
    static_cast<Archer*>(characters[2])->refillArrows();

    // Cleaning up memory
    for (auto character : characters)
    {
        delete character;
    }

    return 0;
}