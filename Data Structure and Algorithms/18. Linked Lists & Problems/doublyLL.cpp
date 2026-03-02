#include <iostream>
using namespace std;

/*
    DLL Class

    Data Members
        1. Integer data
        2. Pointer to next node (nextLL)
        3. Pointer to previous node (previousLL)

    Member Functions
        1. Constructor to initialize data, nextLL and previousLL pointers
*/

class DLL
{
public:
    int data;
    DLL *nextLL, *previousLL;

    DLL(int data)
    {
        this -> data = data;
        this -> nextLL = NULL;
        this -> previousLL = NULL;
    }
};

/*
    countNodes Function() Prototype
*/

int countNodes(DLL* &head);

/*
    insertAtHead() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. Point the nextLL of the new node to the current head
        3. Point the previousLL of the current head to the new node
        4. Update head to point to the new node

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertAtHead(DLL *&head, DLL* &tail, int data)
{
    DLL *newNode = new DLL(data);

    newNode -> nextLL = head;
    head = newNode;

    return;
}

/*
    insertAtTail() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. Point the nextLL of the current tail to the new node
        3. Point the previousLL of the new node to the current tail
        4. Update tail to point to the new node

    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertAtTail(DLL* &head, DLL* &tail, int data)
{
    DLL *newNode = new DLL(data);

    tail -> nextLL = newNode;
    newNode -> previousLL = tail;
    tail = tail -> nextLL;

    return;
}

/*
    insertAtPosition() Function

    Return Type - void

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
        6. Point the previousLL of the new node to the traversal element
        7. Point the nextLL of the traversal element to the new node
        8. Point the previousLL of the next node of traversal element to the new node
        
    Time Complexity: O(n) where n is the position at which the new node is to be inserted
    Space Complexity: O(1)
*/

void insertAtPosition(DLL *&head, DLL *&tail, int position, int data)
{
    int nodes = countNodes(head);

    // Validating the position provided
    if(position > nodes)
    {
        cout << endl << "Invalid position provided!" << endl << endl;
        return;
    }

    DLL *newNode = new DLL(data);
    DLL *traversalElement = head;
    int listCounter = 1;

    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }

    while (listCounter < position - 1 && traversalElement != NULL)
    {
        if (traversalElement -> nextLL -> nextLL == NULL)
        {
            insertAtTail(head, tail, data);
            return;
        }
        traversalElement = traversalElement -> nextLL;
        listCounter++;
    }

    if (traversalElement == NULL)
    {
        cout << endl << "Invalid Position provided!" << endl << endl;
        return;
    }
    else
    {
        traversalElement -> nextLL -> previousLL = newNode;
        newNode -> nextLL = traversalElement -> nextLL;
        traversalElement -> nextLL = newNode;
        newNode -> previousLL = traversalElement;
    }
}

/*
    deleteNodeByPosition() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer position of the node to be deleted

    Approach
        1. If head is NULL, print "List Empty!" and return
        2. If position is 1, update head to point to the next node and delete the current head node
        3. Traverse the list until the position where the node is to be deleted
        4. If end of list is reached before reaching the desired position, print "No such position exists!" and return
        5. Point the nextLL of the previous node of traversal element to the nextLL of the traversal element
        6. Point the previousLL of the next node of traversal element to the previousLL of traversal element
        7. Delete the traversal element
        
    Time Complexity: O(n) where n is the position of the node to be deleted
    Space Complexity: O(1)
*/

void deleteNodeByPosition(DLL *&head, DLL *&tail, int position)
{
    DLL *traversalElement = head, *nodeToDelete;
    int listCounter = 1, nodes = countNodes(head);

    if (head == NULL)
    {
        cout << "List Empty!" << endl;
        return;
    }

    // Validating the position provided
    if(position > nodes)
    {
        cout << endl << "Invalid position provided!" << endl << endl;
        return;
    }

    if (position == 1)
    {
        nodeToDelete = head;
        head = head -> nextLL;
        head -> previousLL = NULL;

        delete nodeToDelete;
        return;
    }

    while (listCounter < position - 1)
    {
        if (traversalElement -> nextLL -> nextLL == tail)
        {
            nodeToDelete = tail;
            tail = tail -> previousLL;
            tail -> nextLL = NULL;
            delete nodeToDelete;
            return;
        }
        traversalElement = traversalElement -> nextLL;
        listCounter++;
    }

    nodeToDelete = traversalElement -> nextLL;
    traversalElement -> nextLL = traversalElement -> nextLL -> nextLL;
    nodeToDelete -> nextLL -> previousLL = traversalElement;
    delete nodeToDelete;

    return;
}

/*
    deleteNodeByData() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer data of the node to be deleted

    Approach
        1. If head is NULL, print "List Empty!" and return
        2. If data of head node matches the data to be deleted, update head to point to the next node and delete the current head node
        3. If data of tail node matches the data to be deleted, update tail to point to the previous node and delete the current tail node
        4. Traverse the list and compare the data of each node with the data to be deleted until end of list is reached
        5. If a node with the desired data is found, point the nextLL of the previous node of traversal element to the nextLL of the traversal
           element and point the previousLL of the next node of traversal element to the previousLL of traversal element and delete traversal
           element and return
        6. If end of list is reached without finding the desired data, print "No data matched [dataToDelete]!" and return

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void deleteNodeByData(DLL* &head, DLL* &tail, int dataToDelete)
{
    DLL *traversalElement = head, *nodeToDelete;

    if(head -> data == dataToDelete)
    {
        nodeToDelete = head;
        head = head -> nextLL;
        head -> previousLL = NULL;
        delete nodeToDelete;
        return;
    }

    if(tail -> data == dataToDelete)
    {
        nodeToDelete = tail;
        tail = tail -> previousLL;
        tail -> nextLL = NULL;
        delete nodeToDelete;
        return;
    }

    while(traversalElement != NULL)
    {
        if(traversalElement -> data == dataToDelete)
        {
            traversalElement -> previousLL -> nextLL = traversalElement -> nextLL;
            traversalElement -> nextLL -> previousLL = traversalElement -> previousLL;
            delete traversalElement;
            return;
        }
        traversalElement = traversalElement -> nextLL;
    }

    cout << endl << "No data matched " << dataToDelete << "!" << endl;

    return;
}

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

void printList(DLL* &head)
{
    cout << endl;
    
    if(head == NULL)
    {
        cout << "List Empty!" << endl << endl;
        return;
    }

    DLL *traversalElement = head;

    while(traversalElement != NULL)
    {
        cout << traversalElement -> data << " ";
        traversalElement = traversalElement -> nextLL;
    }

    cout << endl;
    cout << endl;

    return;
}

/*
    printHeadAndTail() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list

    Approach
        1. Print the data of head and tail nodes
        
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

inline void printHeadAndTail(DLL* &head, DLL* &tail)
{
    if(head == NULL)
    {
        cout << endl << "List Empty!" << endl << endl;
    }
    cout << "Head: " << head -> data << " Tail: " << tail -> data << endl;
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
        3. If end of list is reached without finding the desired data, print "No data matched [dataToSearch]!" and return
        
    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

void searchList(DLL* &head, int toSearch)
{

    // If head is NULL, print "List Empty!" and return
    if(head == NULL)
    {
        cout << endl << "List Empty!" << endl << endl;
        return;
    }

    DLL *traversalElement = head;
    int listCounter = 1;

    while(traversalElement != NULL)
    {
        if(traversalElement -> data == toSearch)
        {
            cout << endl << toSearch << " found at " << listCounter << "th position!" << endl;
            return;
        }
        traversalElement = traversalElement -> nextLL;
        listCounter++;
    }

    cout << endl << "No data matched " << toSearch << "!" << endl << endl;
}

/*
    countNodes() Function

    Return type - Integer

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. Traverse the list and count the number of nodes until end of list is reached
        2. Return the count of nodes

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

int countNodes(DLL* &head)
{
    if(head == NULL)
    {
        return 0;
    }

    DLL *traversalElement = head;
    int nodesCount = 1;

    while(traversalElement != NULL)
    {
        traversalElement = traversalElement -> nextLL;
        nodesCount++;
    }

    return nodesCount;
}