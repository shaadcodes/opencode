#include <iostream>
#include <map>
#include "singlyLL.cpp"

using namespace std;

/*
    removeDuplicates() Function

    Return Type - Pointer to the head of the linked list with duplicates removed.

    Arguments
        1. head - The head of the linked list from which duplicates are to be removed.

    Approach
         1. Check if the head is null, if yes return null as there are no nodes to process.
         2. Create a map to store the occurrence of each data value in the linked list.
         3. Traverse the linked list using a pointer, for each node check if its data value is already
            present in the map.
         4. If the data value is not present in the map, add it to the map and move to the next node.
         5. If the data value is already present in the map, it means it's a duplicate, so remove it by
            adjusting the next pointer of the current node to skip the duplicate node and delete the
            duplicate node from memory.
         6. Continue this process until all nodes have been processed and return the head of the modified
            linked list.

    Time Complexity: O(n) where n is the number of nodes in the linked list, as we need to traverse
    the list once.

    Space Complexity: O(n) in the worst case if all nodes have unique values and are stored in the map,
    where n is the number of nodes in the linked list. However, if there are many duplicates, space
    complexity can be less than O(n).
*/

SLL *removeDuplicates(SLL *head)
{

    if(!head) return head;

    map<int, bool> duplicates;

    SLL *traversalElement = head;

    while(traversalElement != NULL)
    {
        duplicates[traversalElement->data] = true;

        if(duplicates[traversalElement->nextLL->data] == false)
        {
            duplicates[traversalElement->nextLL->data] = true;
            traversalElement = traversalElement->nextLL;
        }
        else
        {
            SLL *duplicate = traversalElement->nextLL;
            traversalElement->nextLL = duplicate->nextLL;
            traversalElement = traversalElement->nextLL;
            delete duplicate;
        }
    }
    return head;
}

// --------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{

    // List Creation
    SLL *head = new SLL(1);

    SLL *tail = head;

    insertAtTail(tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 4);
    insertAtTail(tail, 2);
    insertAtTail(tail, 7);
    insertAtTail(tail, 1);
    insertAtTail(tail, 9);
    insertAtTail(tail, 3);
    insertAtTail(tail, 1);

    printList(head);

    // Duplicates Removal
    head = removeDuplicates(head);

    printList(head);

    return 0;
}