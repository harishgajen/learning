#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    Node* next; // same as "link" in lesson 5
};

Node* head;

void Insert(int x)
{
    Node* temp = new Node; // why can't I do Node* temp = new Node*?? Something about mhow new Node* is for a ** (double) pointer
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
    Node* temp = new Node;
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    printf("How many numbers?\n");
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}