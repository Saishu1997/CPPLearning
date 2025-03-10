/*

A Hash Table (or Hash Map) is a data structure that stores key-value pairs for fast retrieval.
It uses a hash function to compute an index where the data is stored.

*/

#include <iostream>
#include <list>
using namespace std;

class HashTable
{
private:
    static const int TABLE_SIZE = 10;
    list<pair<int, string>> table[TABLE_SIZE];

    int hashFunction(int key)
    {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key, string value)
    {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    string search(int key)
    {
        int index = hashFunction(key);
        for (auto& pair : table[index])
        {
            if (pair.first == key)
            {
                return pair.second;
            }
        }
        return "Not Found";
    }

    void remove(int key)
    {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if(it->first == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << "Bucket" << i << ": ";
            for (auto& pair : table[i])
            {
                cout << "[" <<pair.first << ": " << pair.second << "] ->";
            }
            cout << "nullptr" << endl;
        }
    }
};


int main()
{
    HashTable ht;
    ht.insert(10, "Alice");
    ht.insert(20, "Bob");
    ht.insert(15, "Charlie");
    ht.insert(25, "David");

    ht.display();

    cout << "Searching for key 15: " << ht.search(15) << endl;
    cout << "Searching for key 25: " << ht.search(25) << endl;

    ht.remove(15);
    cout << "After removing key 15: " << endl;
    ht.display();

    return 0;
}