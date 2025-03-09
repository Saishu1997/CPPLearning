/*

An Observer Pattern lets multiple objects listen for changes in a subject.
Used for things like health bars, enemy AI reactions, etc.

Why use Observer?

Multiple objects listen for the same event (UI, AI, etc.).
Decouples systems (UI doesn’t depend on AI).

*/

#include <iostream>
#include <vector>
#include <memory>

//Observer Interface → Any class that wants to listen for events must implement onNotify().
class IObserver
{
public:
    virtual void onNotify(std::string event) = 0;
};

// Subject-> Event Manager
class EventManager
{
private:
    // Stores a list of observers
    std::vector<IObserver*> observers;

public:
    void subscribe(IObserver* observer) // adds new listeners.
    {
        observers.push_back(observer);
    }

    void notify(std::string event) // informs all observers when something happens.
    {
        for (auto observer : observers)
            observer->onNotify(event);
    }
};

// Concrete Observers
class UIManager : public IObserver // listens for game events and updates the UI accordingly.
{
public:
    void onNotify(std::string event) override
    {
        std::cout<< "[UI] Updating UI for event: " << event << std::endl;
    }
};

class AIManager : public IObserver
{
public:
    void onNotify(std::string event) override
    {
        std::cout << "[AI] Enemy AI reacting to event: "<< event << std::endl; 
    }
};

int main()
{
    EventManager eventManager;
    // Subscribes UIManager and AIManager to listen for game events.
    UIManager ui;
    AIManager ai;

    eventManager.subscribe(&ui);
    eventManager.subscribe(&ai);

    // When notify() is called, all observers react accordingly.
    eventManager.notify("Player Attacked");
}