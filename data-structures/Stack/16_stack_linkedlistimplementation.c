#include<stdio.h>
#include<stdlib.h>

// Functions for the linked list implementation of stack
// Insert (push)/delete (pop) at the end of the list - O(n) since we have to traverse the entire node of size n
// Insert (push)/delete (pop) and beginning (head) - O(1)
// Since a stack must have a O(1) for its functions, it makes sense to insert at the beginning instead of at the end of the linked list.

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL; // although we usually call this head, it makes sense to call it top for a stack since a stack is LIFO

void Push(int x) 
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*)); // wait should it be sizeof struct Node* or struct Node?????? I think it should be size of struct node
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop()
{
    if(top == NULL) return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

int main()
{
    Push(4);
    Push(5);
    Pop();
    Pop();
    Pop();
    Pop();
    Push(7);
    printf("%d\n", top->data);
}