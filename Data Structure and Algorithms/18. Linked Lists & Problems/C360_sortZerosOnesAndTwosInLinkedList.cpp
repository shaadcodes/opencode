#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    sortList() Function

    Return Type - pointer to head of the unsorted linked list

    Arguments
        1. Pointer to head of the linked list

    Approach
        1. Check if the head is null or has only one node, if yes return the head as it is already sorted.
        2. Initialize three integer variables, zeros, ones and twos, to count the occurrences of 0s, 1s and 2s in the list.
        3. Traverse the linked list and update the counts of 0s, 1s and 2s based on the data in each node.
        4. Traverse the linked list again and update the data in each node based on the counts of 0s, 1s and 2s.
           First fill in all the 0s, then all the 1s and finally all the 2s.
        5. Return the head of the sorted linked list.

    Time Complexity: O(n) where n is the number of nodes in the linked list, as we need to traverse the list twice.
    Space Complexity: O(1) as we are using only a constant amount of extra space for counting variables and pointers.
*/

SLL *sortList(SLL *head)
{
    if (head == nullptr || head->nextLL == nullptr)
        return head;

    int zeros = 0, ones = 0, twos = 0;
    SLL *traversalElement = head;

    while (traversalElement != nullptr)
    {
        if (traversalElement->data == 0)
            zeros++;

        else if (traversalElement->data == 1)
            ones++;

        else
            twos++;

        traversalElement = traversalElement->nextLL;
    }

    traversalElement = head;

    while (traversalElement != nullptr)
    {
        while (zeros > 0)
        {
            traversalElement->data = 0;
            zeros--;
            traversalElement = traversalElement->nextLL;
        }

        while (ones > 0)
        {
            traversalElement->data = 1;
            ones--;
            traversalElement = traversalElement->nextLL;
        }

        while (twos > 0)
        {
            traversalElement->data = 2;
            twos--;
            traversalElement = traversalElement->nextLL;
        }
    }

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

    // Before Sort
    printList(head);

    sortList(head);

    // After Sort
    printList(head);

    return 0;
}