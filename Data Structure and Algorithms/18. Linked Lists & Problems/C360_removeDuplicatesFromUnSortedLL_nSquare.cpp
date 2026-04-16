#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    removeDuplicates() Function

    Return Type - Pointer to the head of the modified list after removing duplicates.

    Arguments
        1. head - The head of the unsorted singly linked list.

    Approach
         1. Check if the head is null or if there is only one node in the list, if yes return the head as it is.
         2. Initialize a pointer to traverse the list starting from the head.
         3. For each node, initialize another pointer to traverse the rest of the list and compare the data of the current node with the data of the nodes ahead.
         4. If a duplicate is found (current node's data is equal to traversal node's data), remove the duplicate node by adjusting the next pointer of the previous node and deleting the duplicate node from memory.
         5. If no duplicate is found, move the traversal pointer to the next node.
         6. Continue this process until all nodes have been checked for duplicates, ensuring that all duplicates are removed.
         7. Finally, return the head of the modified list.

    Time Complexity: O(n^2) where n is the number of nodes in the linked list, as we need to compare each node with every other node in the worst case.
    Space Complexity: O(1) as we are using only a constant amount of extra space
*/

SLL *removeDuplicates(SLL *head)
{
    if (head == NULL || head->nextLL == NULL)
        return head;

    SLL *currentNode = head;

    while (currentNode->nextLL != NULL)
    {
        SLL *traversalElement = currentNode->nextLL;
        SLL *previousNode = currentNode;

        while (traversalElement != NULL)
        {
            if (currentNode->data == traversalElement->data)
            {
                SLL *duplicate = traversalElement;
                previousNode->nextLL = traversalElement->nextLL;
                traversalElement = previousNode->nextLL;
                delete duplicate;
            }
            else
            {
                previousNode = traversalElement;
                traversalElement = traversalElement->nextLL;
            }
        }
        
        if (currentNode->nextLL != NULL)
            currentNode = currentNode->nextLL;
            
    }
    return head;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    // List Creation
    SLL *head = new SLL(1);
    SLL *tail = head;

    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 7);
    insertAtTail(tail, 7);

    printList(head);

    // Removing Duplicates
    head = removeDuplicates(head);
    printList(head);
}