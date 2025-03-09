/*

The State Machine Pattern allows an object to change its behavior dynamically based on its current state.
It's useful when implementing AI behavior, player movement, or game mode transitions.

Example in Games
A Character AI can be in different states: Idle, Attacking, Chasing, or Dead.
A Game Mode can switch between Main Menu, Playing, and Game Over.

Why Use State Machine?

Easier to manage complex behavior (e.g., AI switching between Attack, Patrol, etc.)
Removes massive if-else chains
Makes adding new states easy (just create a new class without modifying existing code.

*/

#include <iostream>

// Base state interface
class CharacterState
{
public:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual ~CharacterState() {}
};

// Idle State
class IdleState : public CharacterState 
{
public:
    void handleInput() override 
    {
        std::cout << "Idle: Waiting for input...\n";
    }
    
    void update() override 
    {
        std::cout << "Idle: Nothing happens...\n";
    }
};

// Running State
class RunningState : public CharacterState 
{
public:
    void handleInput() override 
    {
        std::cout << "Running: Checking for obstacles...\n";
    }
    
    void update() override 
    {
        std::cout << "Running: Moving forward...\n";
    }
};

// Character Context (Manages Current State)
class Character 
{
private:
    CharacterState* state;
public:
    Character(CharacterState* initialState) : state(initialState) {}
    
    void changeState(CharacterState* newState) 
    {
        state = newState;
    }
    
    void handleInput()
    {
        state->handleInput();
    }
    
    void update() 
    {
        state->update();
    }
};

int main() 
{
    IdleState idle;
    RunningState running;
    
    Character player(&idle);  // Start in Idle state

    player.handleInput();
    player.update();

    std::cout << "--- Changing to Running State ---\n";
    player.changeState(&running);

    player.handleInput();
    player.update();
}
    