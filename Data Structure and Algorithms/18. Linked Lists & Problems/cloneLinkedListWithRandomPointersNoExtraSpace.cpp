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

void insertAtTail(Node* &head, Node* &tail, int data)
    {
        Node *newListNode = new Node(data);
        
        if (head == NULL)
        {
            head = newListNode;
            tail = newListNode;
        }
        else
        {
            tail->next = newListNode;
            tail = newListNode;
        }
    }

Node* cloneLinkedList(Node* head) 
{
    Node *newListHead = NULL;
    Node *newListTail = NULL;
    Node *traversalElement = head;
        
    while (traversalElement != NULL)
    {
        insertAtTail(newListHead, newListTail, traversalElement->data);
        traversalElement = traversalElement->next;
    }
        
    traversalElement = head;
    Node *newTraversalElement = newListHead;
    
    while (traversalElement != NULL)
    {
        Node* nextOriginal = traversalElement->next;
        Node* nextClone = newTraversalElement->next;
            
        traversalElement->next = newTraversalElement;
            
        newTraversalElement->next = nextOriginal;
            
        traversalElement = nextOriginal;
        newTraversalElement = nextClone;
    }
        
    traversalElement = head;
        
    while (traversalElement != NULL)
    {
        if (traversalElement->next != NULL)
        {
            traversalElement->next->random = traversalElement->random 
            ? traversalElement->random->next : traversalElement->random;
        }
            
        traversalElement = traversalElement->next->next;
    }
        
    traversalElement = head;
    newTraversalElement = newListHead;
        
    while (traversalElement != NULL && newTraversalElement != NULL)
    {
        traversalElement->next = newTraversalElement->next;
        traversalElement = traversalElement->next;
            
        if (traversalElement != NULL)
            newTraversalElement->next = traversalElement->next;
                
        newTraversalElement = newTraversalElement->next;

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