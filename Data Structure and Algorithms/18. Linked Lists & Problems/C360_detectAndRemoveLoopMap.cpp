#include <iostream>
#include <map>
#include "singlyLL.cpp"

using namespace std;

/*
    loopExists() Function

    Return Type - Boolean

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Check if the head is null, if yes return false.
        2. Initialize a map to keep track of visited nodes and a pointer to traverse the linked list.
        3. Traverse the linked list until the end is reached, checking if the current node has already been visited.
        4. If a node is found that has already been visited, return true indicating a loop exists.
        5. If the end of the linked list is reached without finding any visited nodes, return false indicating no loop exists.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(n) due to the map storing visited nodes, where n is the number of nodes in the linked list.
*/

bool loopExists(SLL *head)
{
    if (head == NULL)
        return false;

    map<SLL *, bool> visited;
    SLL *temp = head;

    while (temp != NULL)
    {
        if (visited[temp] == true)
            return true;

        visited[temp] = true;
        temp = temp->nextLL;
    }

    return false;
}

/*
    loopStart() Function

    Return Type - Pointer to the node where the loop starts

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Initialize a map to keep track of visited nodes and a pointer to traverse the linked list.
        2. Traverse the linked list until the end is reached, checking if the next node has already been visited.
        3. If a next node is found that has already been visited, return the current node as it is the starting point of the loop.
        4. If the end of the linked list is reached without finding any visited nodes, return null indicating no loop exists.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(n) due to the map storing visited nodes, where n is the number of nodes in the linked list.
*/

SLL *loopStart(SLL *head)
{
    map<SLL *, bool> visited;
    SLL *temp = head;

    while (temp != NULL)
    {
        if (visited[temp->nextLL] == true)
            return temp;

        visited[temp] = true;
        temp = temp->nextLL;
    }

    return NULL;
}

/*
    removeLoop() Function

    Return Type - Pointer to the head of the modified linked list

    Arguments
        1. head - Pointer to the head of the linked list

    Approach
        1. Check if a loop exists in the linked list using the loopExists function, if not return the head as it is.
        2. Find the starting point of the loop using the loopStart function.
        3. Set the next pointer of the node at the starting point of the loop to null, effectively removing the loop.
        4. Return the head of the modified linked list.

    Time Complexity: O(n) where n is the number of nodes in the linked list.
    Space Complexity: O(n) due to the map storing visited nodes, where n is the number of nodes in the linked list.
*/

SLL *removeLoop(SLL *head)
{
    if (!loopExists(head))
        return head;

    SLL *startOfLoop = loopStart(head);

    startOfLoop->nextLL = NULL;

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