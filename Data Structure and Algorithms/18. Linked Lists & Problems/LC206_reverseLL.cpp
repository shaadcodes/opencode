#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    reverseList() Function

    Return Type - Pointer to LL type

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. If head is NULL or head -> nextLL is NULL, return head
        2. Initialize three pointers - previous, forward and current to nullptr, nullptr and head respectively
        3. Traverse the list until current becomes NULL
            a. If current -> nextLL is NULL, point head to current
            b. Point forward to current -> nextLL
            c. Point current -> nextLL to previous
            d. Point previous to current
            e. Point current to forward
        4. Return head

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

SLL* reverseList(SLL* &head) 
{

    SLL* previous = nullptr;
    SLL* forward = nullptr;
    SLL* current = head;

    if (head == nullptr || head -> nextLL == nullptr)
        return head;

    while (current != nullptr)
    {
        if (current -> nextLL == nullptr)
            head = current;
                
        forward = current -> nextLL;
        current -> nextLL = previous;
        previous = current;
        current = forward;
    }

    return head;
}

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    SLL *head = new SLL(20);
    
    insertAtHead(head, 15);
    insertAtHead(head, 10);
    insertAtHead(head, 5);

    cout << endl << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << endl << "Reversed List: ";
    printList(head);

    return 0;
}