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

/*
    isPalindrome() Function

    Return Type - Boolean

    Arguments
        1. Pointer to head of the list

    Approach
        1. If head -> nextLL is NULL, return true
        2. Initialize two pointers - slow and fast to head and head -> nextLL respectively
        3. Traverse the list until fast -> nextLL becomes NULL
            a. Point slow to slow -> nextLL
            b. Point fast to fast -> nextLL
            c. If fast -> nextLL is not NULL, point fast to fast -> nextLL
        4. Point mid to slow -> nextLL and reverse the list from mid to end and point reversedMid to the head of the reversed list
        5. Point slow -> nextLL to reversedMid
        6. Initialize two pointers - traversalElement and comparisonElement to head and reversedMid respectively
        7. Traverse the list until traversalElement becomes equal to reversedMid
            a. If traversalElement -> data is equal to comparisonElement -> data, point traversalElement and comparisonElement to their respective nextLLs
                i. If comparisonElement becomes NULL, return true
            b. Else, return false
        8. Reverse the list from reversedMid to end and point it back to mid and return true

    Time Complexity: O(n) where n is the number of nodes in the list
    Space Complexity: O(1)
*/

bool isPalindrome(SLL *head)
{
        
    if (head->nextLL == nullptr)
        return true;
        
    SLL *slow = head;
    SLL *fast = head->nextLL;
        
    while (fast->nextLL != nullptr)
    {
        slow = slow->nextLL;
        fast = fast->nextLL;
            
        if (fast->nextLL != nullptr)
            fast = fast->nextLL;
    }
        
    SLL *mid = slow->nextLL;
    SLL *reversedMid = reverseList(mid);
    slow->nextLL = reversedMid;
        
    SLL *traversalElement = head;
    SLL *comparisonElement = reversedMid;
        
    while (traversalElement != reversedMid)
    {
        if(traversalElement->data == comparisonElement->data)
        {
            traversalElement = traversalElement->nextLL;
            comparisonElement = comparisonElement->nextLL;
                
            if (comparisonElement == nullptr)
                return true;
        }
        else
        {
            return false;
        }
    }
    reversedMid = reverseList(reversedMid);
    slow->nextLL = reversedMid;
    return true;
}

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    // List Creation
    SLL *head = new SLL(121);
    SLL *tail = head;

    insertAtTail(tail, 320);
    insertAtTail(tail, 121);

    // Before Checking
    printList(head);

    if(isPalindrome(head))
    {
        cout << "Linked List is Palindrome!" << endl;
    }
    else
    {
        cout << "Linked List is NOT Palindrome!" << endl;
    }

    return 0;    
}