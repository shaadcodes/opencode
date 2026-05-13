#include<iostream>
#include "singlyLL.cpp"

using namespace std;

/*
    isPalindrome() Function

    Return Type - boolean value indicating whether the linked list is a palindrome or not

    Arguments
        1. Pointer to head of the linked list

    Approach
        1. Check if the head is null or has only one node, if yes return true as it is a palindrome.
        2. Initialize an empty vector to store the data of the nodes in the linked list.
        3. Traverse the linked list and push the data of each node into the vector.
        4. Initialize two integer variables, start and end, to point to the beginning and end of the vector respectively.
        5. Use a while loop to compare the elements at the start and end indices of the vector. If they are not equal,
            return false as the linked list is not a palindrome. If they are equal, increment the start index and
            decrement the end index.
        6. If the loop completes without finding any mismatch, return true as the linked list is a palindrome.

    Time Complexity: O(n) where n is the number of nodes in the linked list, as we need to traverse the list once to fill the vector and then compare the elements.
    Space Complexity: O(n) as we are using a vector to store the data of the nodes in the linked list, which requires additional space proportional to the number of nodes.

*/

bool isPalindrome(SLL *head)
{
        
    if (head->nextLL == nullptr)
        return true;
        
    vector<int> array;
    SLL *traversalElement = head;
        
    while (traversalElement != nullptr)
    {
        array.push_back(traversalElement->data);
        traversalElement = traversalElement->nextLL;
    }
        
    int start = 0, end = array.size()-1;
        
    while (start <= end)
    {
        if (array[start++] != array[end--])
        return false;
    }
        
    return true;
}

// ---------------------------------------------------MAIN FUNCTION---------------------------------------------------

int main()
{

    // List Creation
    SLL *head = new SLL(1);
    SLL *tail = head;
    
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    //insertAtTail(tail, 6);

    // Before checking for palindrome, let's print the list to verify its contents
    printList(head);

    if(isPalindrome(head))
    {
        cout << "The Linked List is Palindrome!" << endl;
    }
    else
    {
        cout << "The Linked List is NOT Palindrome!" << endl;
    }

    return 0;
}