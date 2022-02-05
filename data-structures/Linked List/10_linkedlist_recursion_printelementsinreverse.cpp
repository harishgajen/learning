#include<stdio.h>
#include<stdlib.h>

// Linked list: Print elements of a linked list in forward and reverse order using recursion
// For normal print (not reverse), an iterative approach will be much more efficient than recursion,
// because we will just use one temp variable. In recursion on the other hand, we will use space in the stack section
// of the memory for so many function calls, so there is implicit use of memory there.
// For reverse print, we will have to store elements in some structure anyways, so if we use recursion it is ok.
// I believe that is because there is no way in linked lists to access the previous node, so we must be storing each address in a variable or something along those lines to
// go in reverse. Fact check this though.

struct Node {
    int data;
    Node* next;
};

// Remember, this is simply a pointer to Node variable, that points to the head node.
// It is not the actual head node itself, but a pointer to that head node.
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

// Printing the elements in the linked list using recursion
void Print(Node* temp) {
    if(temp == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", temp->data);
    Print(temp->next);
}

void PrintReverse(Node* temp) {
    
    // had to remove the printf("\n"); because since that would be done right before printing the first element, it would be done at the beginning of the printf's, 
    // instead of at the beginning
    // Something cool to note is that it only did that \n once anyways, meaning that after the first return, it simply feeds void as the return 
    // to all the places that call the function after that
    // That may not be exactly what is going on, but it is something along those lines, so look into this
    if(temp == NULL) {
        return;
    }
    // By putting the function call before the printf, it will get to the end of the list and start printing there
    // It is as simple as that!
    PrintReverse(temp->next);
    printf("%d ", temp->data);
}

int main()
{
    head = NULL;
    Insert(2, 1);
    Insert(4, 2);
    Insert(6, 3);
    Insert(8, 4);
    Node* temp = head;
    Print(temp);
    PrintReverse(temp);
    printf("\n");
}