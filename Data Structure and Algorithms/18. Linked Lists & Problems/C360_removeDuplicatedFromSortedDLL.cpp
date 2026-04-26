#include <iostream>
#include "doublyLL.cpp"

using namespace std;

/*
    removeDuplicates() Function

    Return Type - Pointer to the head of the modified list after removing duplicates.

    Arguments
        1. head - The head of the sorted doubly linked list.

    Approach
         1. Check if the head is null or if there is only one node in the list, if yes return the head as it is.
         2. Initialize a pointer to traverse the list starting from the head.
         3. Traverse the list until the end is reached, comparing the data of the current node with the next node.
         4. If a duplicate is found (current node's data is equal to next node's data), remove the duplicate node by adjusting the next and previous pointers of the surrounding nodes and deleting the duplicate node from memory.
         5. If no duplicate is found, move the traversal pointer to the next node.
         6. Continue this process until the end of the list is reached, ensuring that all duplicates are removed.
         7. Finally, return the head of the modified list.

    Time Complexity: O(n) where n is the number of nodes in the linked list, as we need to traverse the entire list once.
    Space Complexity: O(1) as we are using only a constant amount of extra space
*/

DLL *removeDuplicates(DLL *head)
{
    if (head == NULL || head->nextLL == NULL)
        return head;

    DLL *traversalElement = head;

    while (traversalElement->nextLL != NULL)
    {
        if (traversalElement->data == traversalElement->nextLL->data)
        {
            DLL *duplicate = traversalElement->nextLL;
            traversalElement->nextLL = traversalElement->nextLL->nextLL;

            if (traversalElement->nextLL != NULL)
                traversalElement->nextLL->previousLL = traversalElement;

            delete duplicate;
        }
        else
        {
            traversalElement = traversalElement->nextLL;
        }
    }
    return head;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    // List Creation
    DLL *head = new DLL(10);
    DLL *tail = head;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 70);
    insertAtTail(head, tail, 80);

    printList(head);

    // Removing Duplicate Nodes
    removeDuplicates(head);

    printList(head);
}