#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node* next;
};

Node* head;

void Insert(int data, int n) {
    Node* temp1 = new Node;
    temp1->data = data;
    temp1->next = NULL;

    if(n==1) {
        temp1->next = head;
        head = temp1; // Remember not to do head->next = temp1, because head needs to point to this new first node. head->next points to the second node
        return;
    }

    Node* temp2 = head;
    for(int i=0; i<n-2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; 
    temp2->next = temp1;
}

// This also covers corner cases when the list is size 0 or size 1
void Reverse() {
    // current is what we usually name as temp
    // Also could have done Node* current = head, prev = NULL;
    Node* current = head; // this is called a pointer to node (I don't think it's called a node pointer)
    Node* prev = NULL; // the node previous to the head node is NULL. 
    Node* next;

    while(current != NULL) {
        // Don't mix up the field next in Node, with the local pointer to Node named next
        // Would it be ok if in an interview I renamed the local variable next so that no one gets mixed  up?
        next = current->next;
        current->next = prev; // same as (*current).next | Also, what's the different if I do *current.next? Maybe that thinks I'm trying to dereference current.next
        prev = current;
        current = next;
    }
    head = prev; // make the head point to the new head node, which is the last node in the original list
}

void Print() {
    Node* temp = head;
    while(temp!=NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    Insert(2, 1);
    Insert(4, 2);
    Insert(6, 3);
    Insert(8, 4);
    Print();
    Reverse();
    Print();
}