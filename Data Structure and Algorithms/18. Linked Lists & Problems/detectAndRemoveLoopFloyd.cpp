#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    loopExists() Function

    Return Type - Pointer to the node where the slow and fast pointers meet (intersection point)

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Initialize two pointers, slow and fast, both starting at the head of the linked list.
        2. Move the slow pointer one step at a time and the fast pointer two steps at a time.
        3. If there is a loop in the linked list, the fast pointer will eventually meet the slow pointer at some point in the loop.
        4. If there is no loop, the fast pointer will reach the end of the linked list (null) without meeting the slow pointer.
        5. Return the node where they meet if a loop exists, otherwise return null.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

SLL *loopExists(SLL *head)
{
    SLL *slow = head, *fast = head;

    while (fast != NULL)
    {
        fast = fast->nextLL;

        if (fast != NULL)
            fast = fast->nextLL;

        slow = slow->nextLL;

        if (fast == slow)
            return slow;
    }

    return NULL;
}

/*
    loopStart() Function

    Return Type - Pointer to the node where the loop starts

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Use the loopExists function to find the intersection point of the slow and fast pointers.
        2. If there is no loop (intersection point is null), return null.
        3. Initialize two pointers, one starting at the head of the linked list and the other starting at the intersection point.
        4. Move both pointers one step at a time until they meet.
        5. The node where they meet will be the starting point of the loop.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(1) as we are using only a constant amount of extra space.
*/

SLL *loopStart(SLL *head)
{
    SLL *intersection = loopExists(head), *slow = head;

    if (intersection == NULL)
        return NULL;

    while (slow != intersection)
    {
        slow = slow->nextLL;
        intersection = intersection->nextLL;
    }

    return slow;
}

/*
    removeLoop() Function

    Return Type - Pointer to the head of the linked list after removing the loop

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Use the loopStart function to find the starting point of the loop.
        2. If there is no loop (starting point is null), return the head as it is.
        3. Initialize a pointer to traverse the loop starting from the node next to the starting point of the loop.
        4. Move the traversal pointer through the loop until it reaches the node just before the starting point of the loop.
        5. Set the next pointer of this node to null, effectively removing the loop from the linked list.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(1) as we are using only a constant amount of extra space
*/

SLL *removeLoop(SLL *head)
{
    if (head == NULL)
        return head;

    SLL *startOfLoop = loopStart(head);

    if (startOfLoop == NULL)
        return head;

    SLL *traversalElement = startOfLoop->nextLL;

    while (traversalElement->nextLL != startOfLoop)
        traversalElement = traversalElement->nextLL;

    traversalElement->nextLL = NULL;

    return head;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{

    // List Creation
    SLL *head = new SLL(10), *tail = head;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 90);

    tail->nextLL = head->nextLL->nextLL;

    // printList(head); -> Prints infinitely

    // Loop Detection & Removal
    removeLoop(head);

    printList(head);

    return 0;
}