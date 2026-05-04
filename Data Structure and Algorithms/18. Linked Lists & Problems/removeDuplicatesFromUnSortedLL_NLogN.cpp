#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    middleOfList() Function

    Return Type - Pointer to the middle node of the linked list.

    Arguments
        1. head - The head of the linked list.

    Approach
         1. Check if the head is null, if yes return null as there is no middle element.
         2. Initialize two pointers, slow and fast, both starting at the head of the list.
         3. Move the slow pointer one step at a time and the fast pointer two steps at a time until the
            fast pointer reaches the end of the list or has no next node.
         4. When the fast pointer reaches the end, the slow pointer will be at the middle of the list.
         5. Return the slow pointer as it points to the middle node.

    Time Complexity: O(n) where n is the number of nodes in the linked list, as we need to traverse the 
    list once.

    Space Complexity: O(1) as we are using only a constant amount of extra space
*/

SLL *middleOfList(SLL *head)
{
    if (!head)
        return head;

    SLL *slow = head;
    SLL *fast = head->nextLL;

    while (fast != NULL && fast->nextLL != NULL)
    {
        slow = slow->nextLL;
        fast = fast->nextLL->nextLL;
    }

    return slow;
}

/*
    mergeList() Function

    Return Type - Pointer to the head of the merged sorted linked list.

    Arguments
        1. left - The head of the left sorted linked list.
        2. right - The head of the right sorted linked list.

    Approach
         1. If the left list is empty, return the right list as the merged result.
         2. If the right list is empty, return the left list as the merged result.
         3. Initialize a pointer to store the head of the merged list.
         4. Compare the data of the current nodes of both lists and recursively merge them by selecting
            the smaller value and linking it to the merged list.
         5. Continue this process until all nodes from both lists are merged into a single sorted linked
            list.
         6. Return the head of the merged sorted linked list.

    Time Complexity: O(n) where n is the total number of nodes in both linked lists, as we need to
    traverse all nodes to merge them.

    Space Complexity: O(n) in the worst case due to recursive calls, where n is the total number of
    nodes in both linked lists. However, the space complexity can be considered O(1) if we ignore the
    recursive stack space, as we are not using any additional data structures to store the merged list.
*/

SLL *mergeList(SLL *left, SLL *right)
{
    if(!left)
        return right;

    if(!right)
        return left;

    SLL *resultList = NULL;

    if (left->data <= right->data)
    {
        resultList = left;
        resultList->nextLL = mergeList(left->nextLL, right);
    }
    else
    {
        resultList = right;
        resultList->nextLL = mergeList(left, right->nextLL);
    }

    return resultList;
}

/*
    sortList() Function

    Return Type - Pointer to the head of the sorted linked list.

    Arguments
        1. head - The head of the linked list to be sorted.

    Approach
         1. Check if the head is null or if there is only one node in the list, if yes return the head as it is.
         2. Find the middle of the linked list using the middleOfList() function.
         3. Split the linked list into two halves by setting the next pointer of the middle node to null.
         4. Recursively call sortList() on both halves of the linked list to sort them individually.
         5. Merge the two sorted halves using the mergeList() function and return the head of the merged sorted linked list.

    Time Complexity: O(n log n) where n is the number of nodes in the linked list, as we are dividing
    the list into halves and merging them back together.

    Space Complexity: O(n) in the worst case due to recursive calls, where n is the number of nodes in
    the linked list. However, the space complexity can be considered O(1) if we ignore the recursive
    stack space, as we are not using any additional data structures to store intermediate results.
*/

SLL *sortList(SLL *head)
{
    if (!head || !head->nextLL)
        return head;

    SLL *middle = middleOfList(head);
    SLL *rightStart = middle->nextLL;
    middle->nextLL = NULL;

    SLL *leftList = sortList(head);
    SLL *rightList = sortList(rightStart);

    return mergeList(leftList, rightList);
}

/*
    removeDuplicates() Function

    Return Type - Pointer to the head of the modified list after removing duplicates.

    Arguments
        1. head - The head of the unsorted linked list.

    Approach
         1. Check if the head is null, if yes return null as there are no duplicates to remove.
         2. Initialize a pointer to traverse the list starting from the head.
         3. Traverse the list until the end is reached, comparing the data of the current node with the
            next node.
         4. If a duplicate is found (current node's data is equal to next node's data), remove the
            duplicate node by adjusting the next pointer of the current node to skip the duplicate node
            and deleting the duplicate node from memory.
         5. If no duplicate is found, move the traversal pointer to the next node.
         6. Continue this process until the end of the list is reached, ensuring that all duplicates are
            removed.
         7. Finally, return the head of the modified list.

    Time Complexity: O(n log n) where n is the number of nodes in the linked list, as we need to sort the
    list first before removing duplicates.

    Space Complexity: O(1) as we are not using any additional data structures to store intermediate results.

*/

SLL *removeDuplicates(SLL *head)
{

    if(!head) return head;

    SLL *traversalElement = head;

    while(traversalElement != NULL && traversalElement->nextLL != NULL)
    {
        if(traversalElement->nextLL->data == traversalElement->data)
        {
            SLL *duplicate = traversalElement->nextLL;
            traversalElement->nextLL = duplicate->nextLL;
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
    SLL *head = new SLL(40);
    SLL *tail = head;

    insertAtTail(tail, 50);
    insertAtTail(tail, 10);
    insertAtTail(tail, 12);
    insertAtTail(tail, 6);
    insertAtTail(tail, 32);
    insertAtTail(tail, 76);
    insertAtTail(tail, 50);
    insertAtTail(tail, 22);
    insertAtTail(tail, 12);

    printList(head);

    head = sortList(head);

    // Sorted List
    head = sortList(head);

    printList(head);

    // Removing Duplicates
    head = removeDuplicates(head);

    printList(head);

    return 0;
}