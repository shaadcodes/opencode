#include <iostream>
#include "circularLL.cpp"

using namespace std;

int main()
{
    CLL *tail = new CLL(15);
    tail -> nextLL = tail;

    // ------------------------------------------------- Insertion Tests ----------------------------------------------

    // Insertion after tail (head)
    insertNode(tail, 15, 90);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;

    // Insertion before tail
    insertNode(tail, 90, 77);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;

    // Insertion in between (after specified element)
    insertNode(tail, 77, 100);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;

    // ------------------------------------------------- Utility Tests ----------------------------------------------

    // Searching tail
    searchList(tail, 15);

    // Searching element after tail (head)
    searchList(tail, 90);

    // Searching specified element
    searchList(tail, 100);

    // ------------------------------------------------- Deletion Tests ----------------------------------------------

    // Deletion of tail
    deleteNode(tail, 15);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;
    
    // Deletion of element after tail (head)
    deleteNode(tail, 90);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;
    
    // Deletion of specified element
    deleteNode(tail, 77);
    printList(tail);
    cout << "Tail: " << tail -> data << endl;
    
    // Deletion of last element
    deleteNode(tail, 100);
    printList(tail);

    return 0;
}