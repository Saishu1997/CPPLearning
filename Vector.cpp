/* A vector is a dynamic array that automatically resizes when elements are added or removed.
It is part of the C++ Standard Library (<vector>).

Key Features of std::vector
Dynamic Resizing: Grows or shrinks automatically.
Contiguous Memory: Like arrays, they store elements sequentially.
Easy to Use: No need to manually manage memory.
Built-in Functions: push_back(), size(), resize(), etc.

Use Vectors When:

You need dynamic resizing.
You want automatic memory management.
You need built-in functions for ease of use.


*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> numbers = {10, 20, 30, 40}; //Dynamic Array
    numbers.push_back(50); //Adds a new element

    cout << "Element at index 2: " << numbers[2] << endl;
    cout << "Vector Size" << numbers.size() << endl;

    return 0;
}