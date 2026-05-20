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
        2. Traverse both lists simultaneously and add the data of corresponding nodes along with carry from previous addition
        3. Insert the result of each addition at the tail of the result list
        4. If one list is longer than the other, continue adding the remaining nodes along with carry until end of longer list is reached
        5. If carry is still not zero after end of both lists is reached, insert carry at the tail of the result list
        6. Reverse the result list to get the final sum in correct order
        7. Remove any trailing zeroes from the result list
    
    Time Complexity: O(max(m, n)) where m and n are the number of nodes in the first and second lists respectively
    Space Complexity: O(max(m, n)) for storing the result list
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
        
    while (firstTE != NULL && secondTE != NULL)
    {
        result = firstTE->data + secondTE->data + carry;
        carry = result/10;
        result = result%10;
            
        insertAtTail(resultHead, resultTail, result);
            
        firstTE = firstTE->nextLL;
        secondTE = secondTE->nextLL;
    }
            
    while (firstTE != NULL)
    {
        if (carry != 0)
        {
            result = firstTE->data + carry;
            carry = result/10;
            result = result%10;
            
            insertAtTail(resultHead, resultTail, result);
                
            firstTE = firstTE->nextLL;
        }
        else
        {
            result = firstTE->data;
            
            insertAtTail(resultHead, resultTail, result);
                
            firstTE = firstTE->nextLL; 
        }
    }
        
    while (secondTE != NULL)
    {
        if (carry != 0)
        {
            result = secondTE->data + carry;
            carry = result/10;
            result = result%10;
                
            insertAtTail(resultHead, resultTail, result);
                
            secondTE = secondTE->nextLL;
        }
        else
        {
            result = secondTE->data;
                
            insertAtTail(resultHead, resultTail, result);
                
            secondTE = secondTE->nextLL; 
        }
    }
        
    while (carry != 0)
    {
        result = carry;
        carry = result/10;
        result = result%10;
                
        insertAtTail(resultHead, resultTail, result);
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