#include <iostream>
#include "singlyLL.cpp"

using namespace std;

int countNodes (SLL* &head)
{
    SLL *traversalElement = head;
    int nodes = 1;

    while (traversalElement != nullptr)
    {
        traversalElement = traversalElement -> nextLL;
        nodes++;
    }

    return nodes;
}

SLL* kReverse(SLL* head, int k) {

    if (head == nullptr)
        return head;

    SLL *traversalElement = head, *nextNode = nullptr;
    SLL *previous = nullptr;
    int count = 1, nodes = countNodes(head);

    if (nodes == nodes%k)
    {
        return traversalElement;
    }

    while (traversalElement != nullptr && count <= k)
    {
        nextNode = traversalElement -> nextLL;
        traversalElement -> nextLL = previous;
        previous = traversalElement;
        traversalElement = nextNode;
        count++;
    }

    if (nextNode != nullptr)
        head -> nextLL = kReverse(nextNode, k);

    return previous;
}

int main()
{
    SLL *head = new SLL(15);
    SLL *tail = head;

    insertAtTail(tail, 56);
    insertAtTail(tail, 32);
    insertAtTail(tail, 11);
    insertAtTail(tail, 90);
    insertAtTail(tail, 10);
    insertAtTail(tail, 5);

    cout << endl << "Before Reversal: ";
    printList(head);
    cout << endl;
    
    head = kReverse(head, 3);
    
    cout << "After Reversal: ";
    printList(head);
    cout << endl;
}