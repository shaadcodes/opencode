#include <iostream>
#include "doublyLL.cpp"
using namespace std;

int main()
{
    DLL *head = new DLL(100); // Head creation
    DLL *tail = head; // Head = Tail for a single node

    // To keep track of Head and Tail pointers
    printHeadAndTail(head, tail);

    // ---------------------------------------------- Insertion Tests ----------------------------------------------

    // Insertion at Head
    insertAtHead(head, tail, 15);
    insertAtHead(head, tail, 56);
    insertAtHead(head, tail, 90);

    printList(head);
    printHeadAndTail(head, tail);

    // Insertion at Tail
    insertAtTail(head, tail, 101);
    insertAtTail(head, tail, 102);
    insertAtTail(head, tail, 103);

    printList(head);
    printHeadAndTail(head, tail);

    // Insertion at specified position
    insertAtPosition(head, tail, 1, 200); // Inserting at Head
    insertAtPosition(head, tail, 9, 300); // Inserting at Tail
    insertAtPosition(head, tail, 4, 400);

    printList(head);
    printHeadAndTail(head, tail);
    
    // ---------------------------------------------- Deletion Tests ----------------------------------------------
    
    // BY POSITION

    // Deleting Head
    deleteNodeByPosition(head, tail, 1);
    printList(head);
    printHeadAndTail(head, tail);

    // Deleting Tail
    deleteNodeByPosition(head, tail, 9);
    printList(head);
    printHeadAndTail(head, tail);

    // Deleting specified position
    deleteNodeByPosition(head, tail, 4);
    printList(head);
    printHeadAndTail(head, tail);

    // BY DATA

    // Deleting Head
    deleteNodeByData(head, tail, 90);
    printList(head);
    printHeadAndTail(head, tail);

    // Deleting Tail
    deleteNodeByData(head, tail, 103);
    printList(head);
    printHeadAndTail(head, tail);

    // Deleting specified data
    deleteNodeByData(head, tail, 100);
    printList(head);
    printHeadAndTail(head, tail);

    // ---------------------------------------------- Utility Tests ----------------------------------------------

    searchList(head, 56); // Searching Head position
    searchList(head, 102); // Searching Tail position
    searchList(head, 400); // Searching random data
    searchList(head, 780); // Searching Non existing element

    // ---------------------------------------------- Edge Cases Tests --------------------------------------------

    DLL *h = new DLL(0);
    DLL *t = h;

    printList(h);
    printHeadAndTail(h, t);

    // Invalid position to insert
    insertAtPosition(h, t, 6, 90);

    printList(h);
    printHeadAndTail(h, t);
    
    // Invalid position to delete
    deleteNodeByPosition(h, t, 7);
    
    printList(h);
    printHeadAndTail(h, t);

    // Invalid data to delete
    deleteNodeByData(h, t, 78);
    printList(h);
    printHeadAndTail(h, t);
    
    return 0;
}