/*

The Composite Pattern allows grouping objects into tree structures to represent part-whole hierarchies.
It's useful when you need to handle individual objects and groups of objects uniformly.

Example in Games
Think of a game scene:

A Scene contains GameObjects (player, enemies, background, UI elements).
A GameObject can have child objects (e.g., an enemy may consist of multiple parts like head, arms, legs).
You want to apply transformations (e.g., move, render) to both individual objects and entire groups.

Why Use Composite?

Helps manage complex hierarchies (e.g., UI elements, scene objects)
Simplifies code by treating single objects and groups the same way
Makes transformations and actions easier (e.g., move all objects in a scene)


*/


#include <iostream>
#include <vector>

// Base component (GameObject)
class GameObject
{
public:
    virtual void render() = 0;
    virtual ~GameObject() {}
};

// Leaf Class -> Individual Game Object
class Sprite : public GameObject
{
private:
    std::string name;
public:
    Sprite(std::string n) : name(n) {}
    void render() override
    {
        std::cout << "Rendering sprite: " << name << std::endl;
    }
};

// Composite class -> Can hold multiple game objects
class Group : public GameObject
{
private:
    std::vector<GameObject*> children;
public:
    void add(GameObject* obj)
    {
        children.push_back(obj);
    }    

    void render() override
    {
        std::cout << "Rendering group \n";
        for (auto child : children)
        {
            child->render();
        }
    }
};

int main()
{
    Sprite player("Player");
    Sprite enemy("Enemy");

    Group scene;
    scene.add(&player);
    scene.add(&enemy);

    scene.render(); // Renders both player and enemy
}