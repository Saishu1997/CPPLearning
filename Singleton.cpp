/*
 A Singleton ensures that there is only one instance of a class. In a game, the 
 GameManager could handle global state, like keeping track of the game level.

GameManager cannot be instantiated directly.
Only one instance is created (getInstance()).
Copying/cloning is disabled.
We use static GameManager* instance to store the single instance.

Why use Singleton?

Ensures only one instance manages game state.
Avoids conflicts when multiple objects try to modify global data.

*/

#include <iostream>

// Singleton class for managing Game State

class GameManager
{
private:
    // static GameManager* instance; → This is a static pointer that will store the single instance of the class.
    static GameManager* instance;
    int level;

    //private constructor → This prevents creating an instance using new GameManager().
    GameManager() : level(1) {}

public: 
    //Deleting copy constructor & assignment operator ensures that nobody can create another instance by copying or assigning the object.
    GameManager(const GameManager&) = delete;
    void operator = (const GameManager&) = delete;

    // Otherwise, we return the already created instance
    static GameManager* getInstance()     // This function ensures that only ONE instance exists.
    {
        if (!instance)  // If instance == nullptr, we create it.
        {
            instance = new GameManager();
        }

        return instance; // Otherwise, we return the already created instance.
    }



    void setLevel(int lvl) {level = lvl;}
    int getLevel() const {return level;}
        
    void display()
    {
        std::cout << "Current Level" << level << std::endl;
    }
};

// Initialize Static Member
GameManager* GameManager::instance = nullptr;

int main()
{
    GameManager* gm = GameManager::getInstance();
    gm->display();
    gm->setLevel(2);
    GameManager::getInstance()->display();
}