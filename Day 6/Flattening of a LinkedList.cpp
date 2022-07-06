#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
Node* merge(Node *h1, Node *h2) {
    Node* h;
    if(h1 -> data > h2 -> data) {
        h = new Node(h2 -> data);
        h2 = h2 -> child;

    }
    else {
        h = new Node(h1 -> data);
        h1 = h1 -> child;

    }
    Node *act = h;
    while(h1 != NULL and h2 != NULL) {
        if(h1 -> data > h2 -> data) {
            Node *temp = new Node(h2 -> data);
            h2 = h2 -> child;
            h -> child = temp;
            h = h -> child;
        }
        else {
            Node * temp = new Node(h1 -> data);
            h1 = h1 -> child;
            h -> child = temp;
            h = h -> child;
       
        }
    }
    while(h1 != NULL) {
        Node * temp = new Node(h1 -> data);
        h1 = h1 -> child;
        h -> child = temp;
        h = h -> child;
 
    }
    while(h2 != NULL) {
        Node * temp = new Node(h2 -> data);
        h2 = h2 -> child;
        h -> child = temp;
        h = h -> child;
 
    }
    return act;
}

Node* flattenLinkedList(Node* head) 
{
    Node *start = head;
    Node* newL = start;
    start = start -> next;
    while(start != NULL) {
        Node *temp = merge(newL,start);
        newL = temp;
        newL -> next = NULL;
        start = start -> next;
    }
    return newL;
}
