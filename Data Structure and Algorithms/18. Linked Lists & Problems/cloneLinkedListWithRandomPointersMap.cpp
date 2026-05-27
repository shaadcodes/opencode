#include <iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

Node* cloneLinkedList(Node* head) 
{
    if (head->next == NULL)
    {
        Node *newListHead = new Node(head->data);
        
        if (head->random == NULL)
        {
            newListHead->random = NULL;
            return newListHead;
        }
            
        newListHead->random = newListHead;
    }
        
    Node *newListHead = new Node(-1);
    Node *newTraversalElement = newListHead;
        
    Node *traversalElement = head;
        
    newTraversalElement->data = traversalElement->data;
    traversalElement = traversalElement->next;
        
    while (traversalElement != NULL)
    {
        Node *newListNode = new Node(traversalElement->data);
            
        newTraversalElement->next = newListNode;
        newTraversalElement = newTraversalElement->next;
        traversalElement = traversalElement->next;
    }
        
    newTraversalElement->next = NULL;
        
    traversalElement = head;
    newTraversalElement = newListHead;

    unordered_map<Node*, Node*> nodeMap;
        
    traversalElement = head;
    newTraversalElement = newListHead;
        
    while (traversalElement != NULL)
    {
        nodeMap[traversalElement] = newTraversalElement;
        traversalElement = traversalElement->next;
        newTraversalElement = newTraversalElement->next;
    }
        
    traversalElement = head;
    newTraversalElement = newListHead;
        
    while (traversalElement != NULL)
    {
        newTraversalElement->random = nodeMap[traversalElement->random];
        newTraversalElement = newTraversalElement->next;
        traversalElement = traversalElement->next;
    }

    return newListHead;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next;
    head->next->random = head;
    head->random->random = head->random->next->next;
    head->random->next->random = head->random;
    head->random->random->random = head->next;

    Node *traversalElement = head;

    cout << endl;
    cout << "Original: " << endl;
    while (traversalElement != NULL)
    {
        cout << traversalElement->data << " - " << traversalElement->random->data << " -> ";
        traversalElement = traversalElement->next;
    }
    cout << endl;
    cout << endl;

    Node *newList = cloneLinkedList(head);

    traversalElement = newList;

    cout << endl;
    cout << "Cloned: " << endl;
    while (traversalElement != NULL)
    {
        cout << traversalElement->data << " - " << traversalElement->random->data << " -> ";
        traversalElement = traversalElement->next;
    }
    cout << endl;
    cout << endl;
    
    return 0;
}