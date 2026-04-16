#include <iostream>
using namespace std;

/*
    CLL Class

    Data Members
        1. Integer data
        2. Pointer to next node (nextLL)

    Member Functions
        1. Constructor to initialize data and nextLL pointer
*/

class CLL
{
    public:

        int data;
        CLL *nextLL = NULL;

        CLL(int data)
        {
            this -> data = data;
            this -> nextLL = this;
        }
};

/*
    insertNode() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the list
        2. Integer data to be inserted

    Approach
        1. If tail is NULL, create a new node with the given data and point tail to it. Point the nextLL of the new node
           to itself and return
        2. If tail is not NULL, print "Incorrect parameters provided!" and return

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertNode(CLL* &tail, int data)
{
    if(tail == NULL)
    {
        CLL *newNode = new CLL(data);
        tail = newNode;
        tail -> nextLL = newNode;
        return;
    }
    else
    {
        cout << endl << "Incorrect parameters provided!" << endl << endl;
        return;
    }
}

/*
    insertNode() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the list
        2. Integer data of the element after which the new node is to be inserted
        3. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. Traverse the list until a node with the data matching the provided element is found or end of list is reached
        3. If a node with the provided element is found, point the nextLL of the new node to the nextLL of the traversal
           element and point the nextLL of traversal element to the new node

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void insertNode(CLL* &tail, int element, int data)
{
    CLL *newNode = new CLL(data);
    CLL *traversalElement = tail;

    while(traversalElement -> data != element && traversalElement -> nextLL != tail)
    {
        traversalElement = traversalElement -> nextLL;
    }

    newNode -> nextLL = traversalElement -> nextLL;
    traversalElement -> nextLL = newNode;
}

/*
    deleteNode() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the list
        2. Integer data of the node to be deleted

    Approach
        1. If tail is NULL, print "List Empty!" and return
        2. Traverse the list until a node with the data matching the provided element is found or end of list is reached
        3. If a node with the provided element is found, point the nextLL of the previous node of traversal element to the
           nextLL of traversal element and delete traversal element

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void deleteNode(CLL* &tail, int dataToDelete)
{
    if(tail == NULL)
    {
        cout << endl << "List Empty!" << endl << endl;
        return;
    }

    CLL *traversalElement = tail, *nodeToDelete;

    while(traversalElement -> nextLL -> data != dataToDelete)
    {
        traversalElement = traversalElement -> nextLL;
    }

    nodeToDelete = traversalElement -> nextLL;

    if(nodeToDelete == tail)
    {
        if(tail -> nextLL == tail)
        {
            delete nodeToDelete;
            tail = NULL;
            return;
        }

        traversalElement -> nextLL = nodeToDelete -> nextLL;
        tail = traversalElement;
        delete nodeToDelete;
    }
    else
    {
        traversalElement -> nextLL = nodeToDelete -> nextLL;
        delete nodeToDelete;
    }
}

/*
    printList() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the list

    Approach
        1. Traverse the list and print the data of each node until end of list is reached

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void printList(CLL* &tail)
{
    CLL *traversalElement = tail;

    cout << endl;

    if(tail == NULL)
    {
        cout << endl << "List Empty!" << endl << endl;
    }

    do
    {
        traversalElement = traversalElement -> nextLL;
        cout << traversalElement -> data << " ";
    }
    while (traversalElement != tail);
    cout << endl;
}

/*
    searchList() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the list
        2. Integer data to be searched

    Approach
        1. Traverse the list and compare the data of each node with the data to be searched until end of list is reached
        2. If a node with the desired data is found, print the position of the node and return
        3. If end of list is reached without finding the desired data, print "No data matched [dataToSearch]!" and return

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void searchList(CLL* &tail, int dataToSearch)
{
    CLL *traversalElement = tail;
    int nodeCount = 0;

    do
    {
        traversalElement = traversalElement -> nextLL;
        nodeCount++;
    }
    while (traversalElement -> data != dataToSearch);

    cout << endl << dataToSearch << " Found at " << nodeCount << "th position!" << endl;
}