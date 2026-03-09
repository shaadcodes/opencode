#include <iostream>
#include "singlyLL.cpp"
using namespace std;

int main()
{
    SLL *node = new SLL(10); // Creation + Initialization of first node
    SLL *head, *tail; // Creation of head and tail pointers

    head = node; // Pointing head to the created node
    tail = head; // pointing tail to the head node (only one node in the list is both head and tail to the list)

    // ------------------------------------------------- Insertion Tests --------------------------------------------------

    // Insertion at head
    insertAtHead(head, 78);
    insertAtHead(head, 65);

    printList(head);
    printHead(head); // Checking position of head
    printTail(tail); // Checking position of tail
    
    // Inasertion at tail
    insertAtTail(tail, 90);
    insertAtTail(tail, 32);
    
    printList(head);
    printHead(head); // Checking position of head
    printTail(tail); // Checking position of tail
    
    // Insertion at position
    insertAtPosition(head, tail, 1, 100);
    insertAtPosition(head, tail, 3, 103);
    insertAtPosition(head, tail, 8, 107);
    
    printList(head);
    printHead(head); // Checking position of head
    printTail(tail); // Checking position of tail

    // ------------------------------------------------- Deletion Tests --------------------------------------------------

    // BY POSITION

    // // Deletion of head node
    deleteNodeByPosition(head, tail, 1);

    printList(head);
    printHead(head);
    printTail(tail);
    
    // Deletion of tail node
    deleteNodeByPosition(head, tail, 7);
    
    printList(head);
    printHead(head);
    printTail(tail);
    
    // Deletion of specified position
    deleteNodeByPosition(head, tail, 4);
    
    printList(head);
    printHead(head);
    printTail(tail);

    // BY DATA ELEMENT

    // Deletion of head node
    deleteNodeByData(head, tail, 100);

    printList(head);
    printHead(head);
    printTail(tail);
    
    // Deletion of tail node
    deleteNodeByData(head, tail, 107);
    
    printList(head);
    printHead(head);
    printTail(tail);
    
    // Deletion of specified data
    deleteNodeByData(head, tail, 78);
    
    printList(head);
    printHead(head);
    printTail(tail);

    // ------------------------------------------------- Utility Tests --------------------------------------------------

    // Searching for an element in the list
    searchList(head, 103);
    searchList(head, 78);

    return 0;
}