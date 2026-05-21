#include <iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    insertAtTail() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list
        2. Reference to pointer to tail of the list
        3. Integer data to be inserted

    Approach
        1. Create a new node with the given data
        2. If the list is empty, point head and tail to the new node
        3. Else, point the nextLL of the current tail to the new node and update tail to point to the new node
    
    Time Complexity: O(1)
    Space Complexity: O(1)
*/

void insertAtTail(SLL* &head, SLL* &tail, int value) 
{
    SLL* newNode = new SLL(value);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->nextLL = newNode;
        tail = newNode;
    }
}

/*
    removeTrailingZeroes() Function

    Return type - void

    Arguments
        1. Reference to pointer to head of the list

    Approach
        1. Traverse the list until a non-zero node is found and update head to point to that node
    
    Time Complexity: O(n) where n is the number of trailing zeroes in the list
    Space Complexity: O(1)
*/

void removeTrailingZeroes(SLL* &head)
{
    while(head->data == 0)
        head = head->nextLL;
}

/*
    addTwoLists() Function

    Return type - pointer to head of the result list

    Arguments
        1. Pointer to head of the first list
        2. Pointer to head of the second list

    Approach
        1. Reverse both lists
        2. Initialize pointers to traverse both lists and variables to store result and carry
        3. Traverse both lists until end of both lists is reached and carry is zero
            a. Calculate sum of current nodes and carry
            b. Update carry for next iteration
            c. Insert the last digit of the sum at the tail of the result list
            d. Move pointers to next nodes in both lists if they are not null
        4. Reverse the result list to get the final sum in correct order

    Time Complexity: O(max(m, n)) where m and n are the number of nodes in the first and second lists respectively
    Space Complexity: O(max(m, n)) for the result list
*/

SLL* addTwoLists(SLL* head1, SLL* head2) 
{       
    head1 = reverseList(head1);
    head2 = reverseList(head2);
        
    SLL *firstTE = head1;
    SLL *secondTE = head2;
        
    int result = 0, carry = 0;
        
    SLL *resultHead = NULL;
    SLL *resultTail = NULL;
        
    while (firstTE != NULL || secondTE != NULL || carry != 0)
    {
        int firstValue = 0;
            
        if (firstTE != NULL)
            firstValue = firstTE->data;
                
        int secondValue = 0;
            
        if (secondTE != NULL)
            secondValue = secondTE->data;
                
        result = firstValue + secondValue + carry;
        carry = result/10;
        result = result%10;
            
        insertAtTail(resultHead, resultTail, result);
            
        if (firstTE != NULL)
            firstTE = firstTE->nextLL;
                
        if  (secondTE != NULL)
            secondTE = secondTE->nextLL;
    }
            
    resultHead = reverseList(resultHead);
        
    removeTrailingZeroes(resultHead);
        
    return resultHead;
}

// ------------------------------------------------- MAIN FUNCTION --------------------------------------------------

int main()
{
    // List Creation

    // LIST 1
    SLL *head1 = new SLL(4);
    SLL *tail1 = head1;

    insertAtTail(head1,tail1, 3);
    insertAtTail(head1, tail1, 8);
    insertAtTail(head1, tail1, 0);

    // LIST 2
    SLL *head2 = new SLL(0);
    SLL *tail2 = head2;

    insertAtTail(head2, tail2, 0);
    insertAtTail(head2, tail2, 7);
    insertAtTail(head2, tail2, 3);
    insertAtTail(head2, tail2, 5);

    printList(head1);
    printList(head2);

    // Adding & Displaying Sum

    SLL *resultList = new SLL(-1);
    resultList = addTwoLists(head1, head2);

    printList(resultList);

    return 0;
}