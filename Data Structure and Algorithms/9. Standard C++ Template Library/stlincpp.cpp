#include <iostream>
using namespace std;

/*
    STL in C++:
        Standard Template Library (STL) is a powerful set of C++ template classes to provide
        general-purpose classes and functions with templates that implement many popular and commonly
        used algorithms and data structures like vectors, lists, queues, and stacks.
        It provides four components called algorithms, containers, functions, and iterators.
        Algorithms: A collection of functions especially designed to be used on ranges of elements.
        Containers: Objects that store data. The STL provides several generic container classes to store objects of a specific type.
        Functions: Function objects (or functors) are objects that can be treated as though they are a function or function pointer.
        Iterators: Objects that enable a C++ program to traverse a container, particularly lists.

    Approach:
        Demonstrate the use of STL components in C++
*/

// vector<> - A dynamic array that can grow or shrink in size
#include <vector>

// list<> - A doubly linked list
#include <list>

// queue<> - A FIFO data structure
#include <queue>

// stack<> - A LIFO data structure
#include <stack>

// algorithm - A collection of functions for various algorithms
#include <algorithm>

// ------------------------------------MAIN FUNCTION--------------------------------------

int main()
{
    // Vector Example
    vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6); // Add element to the end
    cout << "Vector elements: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    // List Example
    list<int> lst = {10, 20, 30};
    lst.push_back(40); // Add element to the end
    cout << "List elements: ";
    for (int num : lst)
    {
        cout << num << " ";
    }
    cout << endl;

    // Queue Example
    queue<int> q;
    q.push(100);
    q.push(200);
    cout << "Queue front element: " << q.front() << endl;
    q.pop();
    cout << "Queue front element after pop: " << q.front() << endl;

    // Stack Example
    stack<int> s;
    s.push(500);
    s.push(600);
    cout << "Stack top element: " << s.top() << endl;
    s.pop();
    cout << "Stack top element after pop: " << s.top() << endl;

    // Algorithm Example - Sorting a vector
    sort(vec.begin(), vec.end(), greater<int>()); // Sort in descending order
    cout << "Sorted Vector elements in descending order: ";
    for (int num : vec)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}