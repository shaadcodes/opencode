#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    lengthOfList() Function

    Return Type - Integer

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. Initialize a traversal element to head and a node count variable to 1
        2. Traverse the list until the nextLL of the traversal element is not NULL, incrementing the node count variable
           at each step
        3. Return the node count variable

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

int lengthOfList(SLL* &head)
{
    SLL *traversalElement = head;
    int nodeCount = 1;

    while(traversalElement -> nextLL != nullptr)
    {
        traversalElement = traversalElement -> nextLL;
        nodeCount++;
    }

    return nodeCount;
}

/*
    findMiddle() Function

    Return Type - Pointer to SLL

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. If head is NULL or the nextLL of head is NULL, return head
        2. Initialize a traversal element to head and a mid variable to length of list divided by 2 + 1
        3. Traverse the list until count is less than or equal to mid - 1, incrementing count at each step
        4. Return the traversal element

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

SLL* findMiddle(SLL* &head)
{
    if (head == nullptr || head -> nextLL == nullptr)
        return head;

    SLL *traversalElement = head;
    int mid = lengthOfList(head)/2 + 1;
    int count = 1;

    while (count <= mid - 1)
    {
        traversalElement = traversalElement -> nextLL;
        count++;
    }

    return traversalElement;
}

// ------------------------------------------------ MAIN FUNCTION --------------------------------------------------

int main()
{
    SLL *head = new SLL(1);
    SLL *tail = head;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);

    cout << endl << "Middle element of the linked list is: " << findMiddle(head) -> data << endl << endl;

    return 0;
}