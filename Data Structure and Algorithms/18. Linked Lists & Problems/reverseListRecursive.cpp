#include <iostream>
#include "singlyLL.cpp"
using namespace std;

/*
    reverseList() Function

    Return Type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Pointer to current node (currentNode)
        3. Pointer to previous node (previous)

    Approach
        1. If currentNode is NULL, point head to previous and return
        2. Recursively call reverseList() with currentNode -> nextLL as currentNode and currentNode as previous
        3. Point currentNode -> nextLL to previous

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(n) due to recursive stack space used for function calls
*/

void reverseList(SLL* &head, SLL* currentNode, SLL* previous)
{
    if (currentNode == NULL)
    {
        head = previous;
        return;
    }

    reverseList(head, currentNode -> nextLL, currentNode);
    currentNode -> nextLL = previous;
}

/*
    reverseList() Function

    Return Type - Pointer to LL type

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. If head is NULL or head -> nextLL is NULL, return head
        2. Recursively call reverseList() with head -> nextLL as argument and store the returned value in newHead
        3. Point head -> nextLL -> nextLL to head
        4. Point head -> nextLL to NULL
        5. Return newHead

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(n) due to recursive stack space used for function calls
*/

SLL* reverseList(SLL* &head)
{
    if(head == nullptr || head -> nextLL == nullptr)
        return head;

    SLL *newHead = reverseList(head -> nextLL);

    head -> nextLL -> nextLL = head;
    head -> nextLL = nullptr;

    return newHead;
}

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    SLL *head = new SLL(20);
    
    insertAtHead(head, 15);
    insertAtHead(head, 10);

    cout << endl << endl << "Recursion 1:" << endl << endl;
    
    cout << "Original List: ";
    printList(head);
    
    reverseList(head, head, nullptr);
    
    cout << endl << "Reversed List: ";
    printList(head);

    cout << endl << endl << "Recursion 2:" << endl << endl;

    SLL *newHead = reverseList(head);
    cout << "Reversed List: ";
    printList(newHead);

    return 0;
}