#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    Node Template Class
    
    A template class for creating nodes of a linked list, where T is the data type of the node's data.
    Each node contains a data member of type T and a pointer to the next node in the linked list. The 
    constructor initializes the data and sets the next pointer to null. The destructor recursively deletes
    the next node to free memory when a node is deleted.

    Variables
        1. data - The data stored in the node of type T.
        2. next - A pointer to the next node in the linked list.

    Time Complexity: O(1) for node creation and deletion.
    Space Complexity: O(1) for each node created, but overall O(n) for n nodes in the linked list.
*/

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

/*
    solve() Function

    Return Type - Pointer to the head of the merged sorted linked list

    Arguments
        1. first - Pointer to the head of the first sorted linked list
        2. second - Pointer to the head of the second sorted linked list

    Approach
        1. If the next pointer of the first linked list is null, set it to point to the second linked list and return the first linked list as the result.
        2. Initialize three pointers: previousptr to keep track of the previous node in the first linked list, nextptr to keep track of the next node in the first linked list, and nodeToCheck to keep track of the current node in the second linked list.
        3. Traverse both linked lists simultaneously, comparing the data of nodeToCheck with previousptr and nextptr.
        4. If nodeToCheck's data is between previousptr's data and nextptr's data, insert nodeToCheck between previousptr and nextptr, update previousptr to nodeToCheck, and move nodeToCheck to the next node in the second linked list.
        5. If nodeToCheck's data is not between previousptr's data and nextptr's data, move previousptr and nextptr forward in the first linked list.
        6. If nextptr reaches null, append any remaining nodes from the second linked list to the end of the first linked list.
        7. Return the head of the merged sorted linked list.

    Time Complexity: O(n + m) where n and m are the number of nodes in the first and second linked lists respectively.
    Space Complexity: O(1) as we are merging the linked lists in place without using any extra space.
*/

Node<int> *solve(Node<int> *first, Node<int> *second)
{
    if (first->next == nullptr)
    {
        first->next = second;
        return first;
    }

    Node<int> *previousptr = first;
    Node<int> *nextptr = first->next;
    Node<int> *nodeToCheck = second;
    Node<int> *nextOfSecond = second->next;

    while (nextptr != nullptr && nodeToCheck != nullptr)
    {
        if (nodeToCheck->data >= previousptr->data && nodeToCheck->data <= nextptr->data)
        {
            nextOfSecond = nodeToCheck->next;
            previousptr->next = nodeToCheck;
            nodeToCheck->next = nextptr;
            previousptr = nodeToCheck;
            nodeToCheck = nextOfSecond;
        }
        else
        {
            previousptr = nextptr;
            nextptr = nextptr->next;

            if (nextptr == nullptr)
            {
                previousptr->next = nodeToCheck;
                return first;
            }
        }
    }
    return first;
}

/*
    sortTwoLists() Function

    Return Type - Pointer to the head of the merged sorted linked list

    Arguments
        1. first - Pointer to the head of the first sorted linked list
        2. second - Pointer to the head of the second sorted linked list

    Approach
        1. Check if either of the linked lists is empty, if so return the other linked list as the result.
        2. Compare the data of the heads of both linked lists and call the solve function with the smaller head as the first argument and the larger head as the second argument.
        3. The solve function will merge the two linked lists in sorted order and return the head of the merged linked list.

    Time Complexity: O(n + m) where n and m are the number of nodes in the first and second linked lists respectively.
    Space Complexity: O(1) as we are merging the linked lists in place without using any extra space.
*/

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (first == nullptr)
        return second;

    if (second == nullptr)
        return first;

    if (first->data <= second->data)
        return solve(first, second);

    else
        return solve(second, first);
}

/*
    printList() Function

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Traverse the linked list starting from the head and print the data of each node until the end of the list is reached.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(1) as we are using only a constant amount of extra space for traversal.
*/

void printList(Node<int> *head)
{
    Node<int> *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{

    Node<int> *first = new Node<int>(1);
    first->next = new Node<int>(3);
    first->next->next = new Node<int>(5);

    Node<int> *second = new Node<int>(2);
    second->next = new Node<int>(4);
    second->next->next = new Node<int>(6);

    printList(first);
    printList(second);

    Node<int> *result = sortTwoLists(first, second);

    printList(result);

    return 0;
}