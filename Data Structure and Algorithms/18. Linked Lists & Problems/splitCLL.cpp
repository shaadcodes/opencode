#include <iostream>
#include "circularLL.cpp"

using namespace std;

/*
    splitList() Function

    Return Type - void

    Arguments
        1. Reference to pointer to tail of the original circular linked list
        2. Reference to pointer to head of the first split circular linked list
        3. Reference to pointer to head of the second split circular linked list

    Approach
        1. Check if the tail is null, if yes print "List Empty!" and return.
        2. Initialize two pointers, slow and fast, both starting at the node next to tail (head of the list).
        3. Move the slow pointer one step at a time and the fast pointer two steps at a time until the fast
           pointer reaches the tail or has no next node.
        4. When the fast pointer reaches the tail, the slow pointer will be at the middle of the list.
        5. Split the list into two halves by adjusting the next pointers of the nodes at the middle and tail.
        6. Set firstHead to point to the head of the first split list and secondHead to point to the head of
           the second split list.

    Time Complexity: O(n) where n is the number of nodes in the circular linked list, as we need to traverse
    the list once.

    Space Complexity: O(1) as we are using only a constant amount of extra space for pointers.
*/

void splitList(CLL* &tail, CLL* &firstHead, CLL* &secondHead)
{

    if(!tail)
    {
        cout << "List Empty!" << endl;
        return;
    }

    CLL *middle, *start;
    CLL *slow = tail->nextLL;
    CLL *fast = slow;

    while(fast != tail && fast->nextLL != tail)
    {
        slow = slow->nextLL;
        fast = fast->nextLL->nextLL;
    }
    
    start = tail->nextLL;
    middle = slow->nextLL;
    slow->nextLL = start;
    tail->nextLL = middle;

    firstHead = start;
    secondHead = middle;
}

/*
    printSplit() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the circular linked list to be printed

    Approach
        1. Check if the head is null, if yes print "List Empty!" and return.
        2. Traverse the circular linked list starting from the head and print the data of each node until
           we come back to the head.

    Time Complexity: O(n) where n is the number of nodes in the circular linked list, as we need to traverse
    the list once.

    Space Complexity: O(1) as we are using only a constant amount of extra space for pointers.
*/

void printSplit(CLL* &head)
{

    if(!head)
    {
        cout << "List Empty!" << endl;
        return;
    }

    CLL *traversalElement = head;

    do
    {
        cout << traversalElement->data << " ";
        traversalElement = traversalElement->nextLL;
    }
    while(traversalElement != head);

    cout << endl;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{

    // List Creation
    CLL *tail = new CLL(50);
    CLL *firstHead = NULL, *secondHead = NULL;

    insertNode(tail, 50, 30);
    insertNode(tail, 30, 10);
    insertNode(tail, 10, 40);
    insertNode(tail, 40, 11);
    insertNode(tail, 11, 67);
    insertNode(tail, 67, 89);
    insertNode(tail, 89, 61);

    printList(tail);

    // Splitting the list
    splitList(tail, firstHead, secondHead);

    // Printing the resultant lists
    cout << "First List: " << endl;
    printSplit(firstHead);

    cout << "Second List: " << endl;
    printSplit(secondHead);

    return 0;
}