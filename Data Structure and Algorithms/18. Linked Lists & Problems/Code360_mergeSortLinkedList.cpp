#include <iostream>
#include "singlyLL.cpp"

using namespace std;

SLL* getMid(SLL* &head)
{
    SLL *slow = head;
    SLL *fast = head->nextLL;

    while (fast != nullptr && fast->nextLL != nullptr)
    {
        slow = slow->nextLL;
        fast = fast->nextLL->nextLL;
    }
    return slow;
}

SLL* mergedList(SLL* &leftPart, SLL* &rightPart)
{
    if (leftPart == nullptr)
        return rightPart;

    if (rightPart == nullptr)
        return leftPart;

    SLL *newListHead = new SLL(-1);
    SLL *traversalElement = newListHead;

    while (leftPart != nullptr && rightPart != nullptr)
    {
        if (leftPart->data < rightPart->data)
        {
            traversalElement->nextLL = leftPart;
            traversalElement = leftPart;
            leftPart = leftPart->nextLL;
        }
        else
        {
            traversalElement->nextLL = rightPart;
            traversalElement = rightPart;
            rightPart = rightPart->nextLL;
        }
    }

    while (leftPart != nullptr)
    {
        traversalElement->nextLL = leftPart;
        traversalElement = leftPart;
        leftPart = leftPart->nextLL;
    }

    while (rightPart != nullptr)
    {
        traversalElement->nextLL = rightPart;
        traversalElement = rightPart;
        rightPart = rightPart->nextLL;
    }

    newListHead = newListHead->nextLL;

    return newListHead;
}

SLL* mergeSort(SLL* &head)
{
    if (head == nullptr || head->nextLL == nullptr)
    {
        return head;
    }

    SLL *mid = getMid(head);

    SLL *left = head;
    SLL *right = mid->nextLL;

    mid->nextLL = nullptr;

    left = mergeSort(left);
    right = mergeSort(right);

    return mergedList(left, right);
}

int main()
{
    SLL *head = new SLL(71);
    SLL *tail = head;

    // 71 59 50 21 90 50 44 84 81 18 
    insertAtTail(tail, 59);
    insertAtTail(tail, 50);
    insertAtTail(tail, 21);
    insertAtTail(tail, 90);
    insertAtTail(tail, 50);
    insertAtTail(tail, 44);
    insertAtTail(tail, 84);
    insertAtTail(tail, 81);
    insertAtTail(tail, 18);

    printList(head);

    head = mergeSort(head);

    printList(head);

    return 0;
}