#include <iostream>

using namespace std;

class Node {
public:
 	int data;
	Node *next;
  	Node *child;
	Node() : data(0), next(nullptr), child(nullptr){};
 	Node(int x) : data(x), next(nullptr), child(nullptr) {}
	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

Node* merge(Node* &left, Node* &right)
{
	if (left == nullptr)
		return right;

	if (right == nullptr)
		return left;

	Node *newListHead = new Node(-1);
	Node *traversalElement = newListHead;

	while (left != nullptr && right != nullptr)
	{
		if (left->data < right->data)
		{
			traversalElement->child = left;
			traversalElement = left;
			left = left->child;
		}
		else
		{
			traversalElement->child = right;
			traversalElement = right;
			right = right->child;
		}
	}

	while (left != nullptr)
	{
		traversalElement->child = left;
		traversalElement = left;
		left = left->child;
	}

	while (right != nullptr)
	{
		traversalElement->child = right;
		traversalElement = right;
		right = right->child;
	}

	newListHead = newListHead->child;

	return newListHead;
}

Node* flattenLinkedList(Node* head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;
		
	Node *traversalElement = head;
	Node *nextHead = flattenLinkedList(head->next);

	traversalElement->next = nullptr;

	Node *resultListHead = merge(traversalElement, nextHead);

	return resultListHead;
}

void printList(Node *head)
{
    Node *traversalElement = head;

    while (traversalElement != nullptr)
    {
        cout << traversalElement->data << " ";
        traversalElement = traversalElement->child;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->child = new Node(4);
    head->child->next = new Node(5);
    head->child->child = new Node(6);
    head->child->child->child = new Node(7);

    Node *flattenedListHead = flattenLinkedList(head);

    printList(flattenedListHead);

    return 0;
}