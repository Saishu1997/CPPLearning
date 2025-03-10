/* 

An array is a fixed-size collection of elements of the same type stored in contiguous memory.

Key Features of Arrays

Fixed Size: You must specify the size at declaration.
Contiguous Memory: Elements are stored sequentially.
Fast Access: O(1) time complexity for accessing elements.
No Dynamic Resizing: Cannot grow or shrink during runtime.

Use Arrays When:

You need fast performance with fixed-size data.
You want manual control over memory allocation.
The size is known at compile-time.

*/
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {10, 20, 30, 40, 50}; //Fixed size array
    cout << "Element at index 2:" << arr[2] << endl;
    return 0;
}