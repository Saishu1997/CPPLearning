/*

A Factory creates objects dynamically without specifying their exact class.
This is useful for game characters, weapons, enemies, etc.

Why use Factory?

Decouples object creation (no need for new everywhere).
Easier to extend (just add a new subclass).

*/

#include <iostream>
#include <memory>


// Base class GameCharacter represents any in-game character.
class GameCharacter 
{
protected:
    std::string name;

public:
    GameCharacter(std::string n) : name(n) {}
    virtual void attack() = 0; // The attack() function is pure virtual, meaning subclasses must implement it.
    virtual ~GameCharacter() {}
};

// The Warrior class inherits from GameCharacter.
class Warrior : public GameCharacter 
{
public:
    Warrior(std::string n) : GameCharacter(n) {}
    void attack() override 
    {
        std::cout << name << " swings a mighty sword!" << std::endl;
    }
};
    
class Mage : public GameCharacter 
{
public:
    Mage(std::string n) : GameCharacter(n) {}
    void attack() override 
    {
        std::cout << name << " casts a fireball!" << std::endl;
    }
};

class CharacterFactory
{
public:
    // std::unique_ptr<GameCharacter> ensures memory is managed automatically.
    static std::unique_ptr<GameCharacter> createCharacter(std::string type, std::string name)
    {
        // Instead of writing new Warrior("Aragon") everywhere, we use the factory method to create characters dynamically.
        if (type == "Warrior") return std::make_unique<Warrior>(name);
        if (type == "Mage") return std::make_unique<Mage>(name);
        return nullptr;
    }
};


int main()
{
    auto warrior = CharacterFactory::createCharacter("Warrior", "Aragon");
    auto mage = CharacterFactory::createCharacter("Mage", "Gandalf");

    warrior->attack();
    mage->attack();
}