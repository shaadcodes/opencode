#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    insertNodeAtTail() Function

    Return Type - void

    Arguments
        1. Pointer to the reference of tail of the node of either zero, one or two
        2. Pointer to the node to be inserted at the tail of either zero, one or two

    Approach
        1. Set the next pointer of the current tail to the node to be inserted.
        2. Update the tail pointer to point to the newly inserted node. 

    Time Complexity: O(1) as we are inserting the node at the tail in constant time.
    Space Complexity: O(1) as we are using only a constant amount of extra space for the pointers.
*/

inline void insertNodeAtTail(SLL *&tail, SLL *nodeToInsert)
{
    tail->nextLL = nodeToInsert;
    tail = tail->nextLL;
}

/*
    sortList() Function

    Return Type - Pointer to the head of the unsorted linked list

    Arguments
        1. Pointer to the head of the linked list to be sorted

    Approach
        1. Create three dummy nodes for zero, one and two and maintain three tail pointers for each of them.
        2. Traverse the original linked list and insert each node at the tail of the corresponding dummy node based on its data value (0, 1 or 2).
        3. Connect the three sublists together by updating the next pointers of the tail nodes.
        4. Update the head pointer to point to the head of the sorted linked list.

    Time Complexity: O(n) as we are traversing the linked list once.
    Space Complexity: O(1) as we are using only a constant amount of extra space for the dummy nodes and tail pointers.
*/

SLL *sortList(SLL *head)
{

    SLL *zeroHead = new SLL(-1);
    SLL *zeroTail = zeroHead;

    SLL *oneHead = new SLL(-1);
    SLL *oneTail = oneHead;

    SLL *twoHead = new SLL(-1);
    SLL *twoTail = twoHead;

    SLL *traversalElement = head;

    while (traversalElement != nullptr)
    {
        if (traversalElement->data == 0)
            insertNodeAtTail(zeroTail, traversalElement);

        else if (traversalElement->data == 1)
            insertNodeAtTail(oneTail, traversalElement);

        else
            insertNodeAtTail(twoTail, traversalElement);

        traversalElement = traversalElement->nextLL;
    }
    
    if (oneHead->nextLL != nullptr)
        zeroTail->nextLL = oneHead->nextLL;
    else
        zeroTail->nextLL = twoHead->nextLL;
    
    oneTail->nextLL = twoHead->nextLL;
    twoTail->nextLL = nullptr;
    
    head = zeroHead->nextLL;
    
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------

int main()
{

    // List Creation
    SLL *head = new SLL(2);
    SLL *tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 1);
    insertAtTail(tail, 0);
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);

    tail->nextLL = nullptr;

    // Before Sort
    printList(head);

    head = sortList(head);

    // After Sort
    printList(head);

    return 0;
}