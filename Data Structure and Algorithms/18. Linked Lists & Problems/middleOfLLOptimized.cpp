#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    findMiddle() Function

    Return Type - Pointer to SLL

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. If head is NULL or the nextLL of head is NULL, return head
        2. Initialize two pointers, slow and fast, to head and the nextLL of head respectively
        3. Traverse the list until fast is not NULL, moving slow by one step and fast by two steps at each iteration
        4. Return the slow pointer

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

SLL* findMiddle(SLL* &head)
{
    if (head == nullptr || head -> nextLL == nullptr)
        return head;

    SLL *slow = head, *fast = head -> nextLL;

    while (fast != nullptr)
    {
        fast = fast -> nextLL;

        if (fast != nullptr)
        {
            fast = fast -> nextLL;
        }
        
        slow = slow -> nextLL;
    }

    return slow;
}

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    SLL *head = new SLL(10);
    SLL *tail = head;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    insertAtTail(tail, 60);

    cout << endl << "Middle Element: " << findMiddle(head) -> data << endl << endl;

    return 0;
}