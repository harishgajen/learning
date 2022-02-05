#include<stdio.h>
#include<stdlib.h>

struct Node {
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
        head = temp1;
        return;
    }

    Node* temp2 = head;
    for(int i=0; i<n-2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Reverse(Node* p) {
    if(p->next == NULL) {
        head = p;
        return;
    }
    Reverse(p->next);
    Node* q = p->next;
    q->next = p; // same as doing p->next->next = p
    p->next = NULL;
}
void Print() {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    head = NULL;
    Insert(2, 1);
    Insert(4, 2);
    Insert(8, 3);
    Insert(6, 3);
    Print();
    printf("current head: %d\n", head);
    Reverse(head);
    printf("checking if head is the same head: %d\n", head);
    // Head does change, but it should be changing, since we reversed the list so it makes sense
    // In something like reverse print using recursion, it will stay the same
    Print();
}
