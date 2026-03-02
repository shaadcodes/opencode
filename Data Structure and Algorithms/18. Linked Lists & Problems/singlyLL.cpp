
#include <iostream>
using namespace std;

/*
    SLL Class

    Data Members
        1. Integer data
        2. Pointer to next node (nextLL)

    Member Functions
        1. Constructor to initialize data and nextLL pointer

    Approach
        1. Create a class SLL to represent a node in the singly linked list
        2. Implement functions to insert nodes at head, tail and specific position
        3. Implement functions to delete nodes by position and by data element
        4. Implement function to print the list, head and tail elements, and search for an element in the list
*/

class SLL
{
    public:
        int data;
        SLL *nextLL = NULL;

        SLL(int data)
        {
            this -> data = data;
            this -> nextLL = NULL;
        }
};

// ------------------------------------------------- Insertion Functions --------------------------------------------------

/*
    insertAtHead() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. Point the nextLL of the new node to the current head
        3. Update head to point to the new node
        
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertAtHead(SLL* &head, int data)
{
    SLL *newNode = new SLL(data);
    newNode -> nextLL = head;
    head = newNode;
}

/*
    insertAtTail() Function

    Return type - void

    Arguments
        1. Reference to pointer to tail of the list
        2. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. Point the nextLL of the current tail to the new node
        3. Update tail to point to the new node
        
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertAtTail(SLL* &tail, int data)
{
    SLL *newNode = new SLL(data);
    tail -> nextLL = newNode;
    tail = tail -> nextLL;
}

/*
    insertAtPosition() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer position where the new node is to be inserted
        4. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. If position is 1, call insertAtHead() function
        3. Traverse the list until the position where the new node is to be inserted
        4. If end of list is reached before reaching the desired position, call insertAtTail() function
        5. Point the nextLL of the new node to the nextLL of the traversal element
        6. Point the nextLL of the traversal element to the new node
        
    Time Complexity: O(n) where n is the position at which the new node is to be inserted
    Space Complexity: O(1)
*/

void insertAtPosition(SLL* &head, SLL* &tail, int position, int data)
{
    SLL *newNode = new SLL(data);
    SLL *traversalElement;
    int listCounter = 1;
    traversalElement = head;

    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    while(listCounter < position - 1)
    {
        if(traversalElement -> nextLL -> nextLL == NULL)
        {
            insertAtTail(tail, data);
            return;
        }

        traversalElement = traversalElement -> nextLL;
        listCounter++;
    }

    newNode -> nextLL = traversalElement -> nextLL;
    traversalElement -> nextLL = newNode;

    return;
}

// ------------------------------------------------- Deletion Functions --------------------------------------------------

/*
    deleteNodeByPosition() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer position of the node to be deleted

    Approach
        1. If head is NULL, print "List Empty!" and return
        2. If position is 1, update head to point to the next node and delete the current head node
        3. Traverse the list until the position where the node is to be deleted
        4. If end of list is reached before reaching the desired position, print "No such position exists!" and return
        5. Point the nextLL of the traversal element to the nextLL of the node to be deleted
        6. If the node to be deleted is tail, update tail to point to the traversal element
        
    Time Complexity: O(n) where n is the position of the node to be deleted
    Space Complexity: O(1)
*/

void deleteNodeByPosition(SLL* &head, SLL* &tail, int position)
{

    if(head == NULL)
    {
        cout << "List Empty!" << endl;
        return;
    }

    SLL *traversalElement = head, *toDelete;
    int listCounter = 1;

    if(position == 1)
    {
        toDelete = head;
        head = head -> nextLL;
        delete toDelete;
        return;
    }

    while(listCounter < position - 1)
    {
        
        traversalElement = traversalElement -> nextLL;
        listCounter++;

        if(traversalElement -> nextLL == tail)
        {
            toDelete = tail;
            tail = traversalElement;
            tail -> nextLL = NULL;
            delete toDelete;
            return;
        }
    }

    toDelete = traversalElement -> nextLL;
    traversalElement -> nextLL = toDelete -> nextLL;
    toDelete -> nextLL = NULL;
    delete toDelete;

    return;
}

/*
    deleteNodeByData() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer data of the node to be deleted

    Approach
        1. If head is NULL, print "List Empty!" and return
        2. If head node contains the data to be deleted, update head to point to the next node and delete the current head node
        3. Traverse the list until the node containing the data to be deleted is found
        4. If end of list is reached before finding the desired data, print "No such data exists!" and return
        5. Point the nextLL of the traversal element to the nextLL of the node to be deleted
        6. If the node to be deleted is tail, update tail to point to the traversal element
        
    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void deleteNodeByData(SLL* &head, SLL* &tail, int dataToDelete)
{
    SLL *traversalElement = head, *nodeToDelete;

    if(head == NULL)
    {
        cout << "List Empty!" << endl;
        return;
    }

    if(head -> data == dataToDelete)
    {
        head = head -> nextLL;
        delete traversalElement;
        return;
    }

    while(traversalElement -> nextLL != NULL)
    {
        if(traversalElement -> nextLL -> data == dataToDelete)
        {
            if(traversalElement -> nextLL == tail)
            {
                nodeToDelete = tail;
                tail = traversalElement;
                tail -> nextLL = NULL;
                delete nodeToDelete;
                return;
            }
            nodeToDelete = traversalElement -> nextLL;
            traversalElement -> nextLL = traversalElement -> nextLL -> nextLL;
            delete nodeToDelete;
            return;
        }
        traversalElement = traversalElement -> nextLL; 
    }

    cout << "No such data exists!" << endl;

    return;
}

// ------------------------------------------------- Utility Functions --------------------------------------------------

/*
    printList() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. Traverse the list and print the data of each node until end of list is reached
        
    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void printList(SLL* &head)
{
    cout << endl;
    SLL *traversalElement;
    traversalElement = head;
    do
    {
        cout << traversalElement -> data << " ";
        traversalElement = traversalElement -> nextLL;
    }
    while (traversalElement != NULL);
    cout << endl;

    return;
}

/*
    printHead() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. Print the data of the head node
        
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void printHead(SLL* &head)
{
    cout << head -> data << endl;
}

/*
    printTail() Function

    Return type - void

    Arguments
        1. Reference to pointer to tail of the list

    Approach
        1. Print the data of the tail node
        
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void printTail(SLL* &tail)
{
    cout << tail -> data << endl;
}

/*
    searchList() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Integer data to be searched

    Approach
        1. Traverse the list and compare the data of each node with the data to be searched until end of list is reached
        2. If a node with the desired data is found, print the position of the node and return
        3. If end of list is reached without finding the desired data, print "not found in List!" and return
        
    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void searchList(SLL* &head, int toSearch)
{
    SLL *traversalElement = head;
    int listCount = 1;

    while(traversalElement != NULL)
    {
        if(traversalElement -> data == toSearch)
        {
            cout << "Found at " << listCount << "th position!" << endl;
            return;
        }
        traversalElement = traversalElement -> nextLL;
        listCount++;
    }
    cout << toSearch << " not found in List!" << endl;

    return;
}