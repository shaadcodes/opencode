#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    countNodes() Function

    Return Type - Integer

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Initialize a pointer to traverse the linked list and a variable to count the number of nodes.
        2. Traverse the linked list until the end is reached, incrementing the count variable for each node encountered.
        3. Return the count of nodes.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

int countNodes(SLL *&head)
{
    SLL *traversalElement = head;
    int nodes = 1;

    while (traversalElement != nullptr)
    {
        traversalElement = traversalElement->nextLL;
        nodes++;
    }

    return nodes;
}

/*
    kReverse() Function

    Return Type - Pointer to the head of the modified linked list

    Arguments
        1. head - Pointer to the head of the linked list
        2. k - The number of nodes to reverse in each group

    Approach
        1. Check if the head is null, if yes return null.
        2. Initialize pointers for traversal, next node, and previous node, and a count variable.
        3. Count the total number of nodes in the linked list.
        4. If the total number of nodes is less than k, return the head as it is.
        5. Traverse the linked list and reverse the first k nodes.
        6. If there are more nodes to process, recursively call kReverse for the next group of nodes and connect it to the current group.
        7. Return the new head of the reversed linked list.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(n/k) due to recursive calls, where n is the number of nodes and k is the group size.
*/

SLL *kReverse(SLL *head, int k)
{

    if (head == nullptr)
        return head;

    SLL *traversalElement = head, *nextNode = nullptr;
    SLL *previous = nullptr;
    int count = 1, nodes = countNodes(head);

    if (nodes == nodes % k)
    {
        return traversalElement;
    }

    while (traversalElement != nullptr && count <= k)
    {
        nextNode = traversalElement->nextLL;
        traversalElement->nextLL = previous;
        previous = traversalElement;
        traversalElement = nextNode;
        count++;
    }

    if (nextNode != nullptr)
        head->nextLL = kReverse(nextNode, k);

    return previous;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    SLL *head = new SLL(15);
    SLL *tail = head;

    insertAtTail(tail, 56);
    insertAtTail(tail, 32);
    insertAtTail(tail, 11);
    insertAtTail(tail, 90);
    insertAtTail(tail, 10);
    insertAtTail(tail, 5);

    cout << endl
         << "Before Reversal: ";
    printList(head);
    cout << endl;

    head = kReverse(head, 3);

    cout << "After Reversal: ";
    printList(head);
    cout << endl;
}