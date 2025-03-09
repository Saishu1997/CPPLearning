/*

A Strategy Pattern allows an object to swap behaviors at runtime.
Great for different attack strategies in a game.


Why use Strategy?

Easily switch behaviors at runtime.
Encapsulates different attack styles.

*/

#include <iostream>
#include <memory>

// Strategy Interface
class AttackStrategy
{
public:
    virtual void attack(std::string name) = 0;
};

// A concrete attack strategy (sword attack).
class SwordAttack : public AttackStrategy
{
public:
    void attack(std::string name) override
    {
        std::cout << name << "slashes with sword!" << std::endl;
    }
};

// A different attack strategy (fireball attack).
class FireballAttack : public AttackStrategy
{
public:
    void attack(std::string name) override
    {
        std::cout << name << "casts a fireball!" << std::endl;
    }
};

class Character
{
private:
    std::string name;
    std::unique_ptr<AttackStrategy> attackStrategy; // Character class holds an attack strategy

public:
    Character(std::string n, std::unique_ptr<AttackStrategy> strategy)
        :name(n), attackStrategy(std::move(strategy)) {}

    // allows changing the attack at runtime.
    void setAttackStrategy(std::unique_ptr<AttackStrategy> strategy)
    {
        attackStrategy = std::move(strategy);
    }

    void performAttack()
    {
        attackStrategy->attack(name);
    }
};

int main()
{
    //Initially uses SwordAttack.
    Character warrior("Aragon", std::make_unique<SwordAttack>());
    warrior.performAttack();

    // Switches to FireballAttack dynamically.
    warrior.setAttackStrategy(std::make_unique<FireballAttack>());
    warrior.performAttack();
}