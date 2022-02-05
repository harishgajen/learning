#include<stdio.h>
#include<stdlib.h>

// Linked list: Deleting node at nth position
// Note: when we do something like temp1->data, that is the same as doing (*temp1).data, dereferencing the pointer temp1

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

// probably bad practice to name the function Delete when there is another function, delete, that is the equivalent of free in C, for dynamic memory allocation (removing data from the heap)
// Delete note at position n (considering first position as 1)
void DeleteNode(int n) {
    Node* temp1 = head;
    if(n==1) {
        head = temp1 -> next; // head now points to the second node
        delete(temp1);
        return;
    }
    int i;
    for(int i=0; i<n-2; i++) {
        temp1 = temp1 -> next;
    }
    // temp1 now points to the nth-1 node
    Node* temp2 = temp1->next; // nth node
    temp1->next = temp2->next; // temp1's next pointer now points to the nth+1 node
    delete(temp2);
}

// Delete first node with data of x
void DeleteNode1(int x) {
    Node* temp1 = head;
    if(head->data == x) {
        head = temp1 -> next; // head now points to the second node
        delete(temp1);
        return;
    }

    // Try with a different condition, like temp1 != NULL. I think this works too though, because say it is the last node, we are checking if the second last node's next pointer's derefenced data is equal to what we are looking for
    // We need the node before the node that has data x to be our temp1 anyways
    while(temp1->next != NULL) {
        if((temp1->next)->data == x) break;
        temp1 = temp1->next;
    }
    if(temp1 == NULL) {
        printf("The value given is not in the linked list\n");
        return;
    }

    // temp1 now points to the node before the node with data x
    Node* temp2 = temp1->next; // node with data x
    temp1->next = temp2->next; // temp1's next pointer now points to the node after the node with data x
    delete(temp2); // freeing dynamic memory holding node with data x
}

void Print() {
    Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL; // Empty list
    Insert(2, 1); // List: 2
    Insert(4, 2); // List: 2,4
    Insert(3, 2); // List: 2,3,4
    Insert(5, 4); // List: 2,3,4,5
    Insert(16, 1); // List: 16,2,3,4,5
    Print(); 
    printf("Enter a position\n");
    int n;
    scanf("%d",&n);
    DeleteNode(n);
    Print();
    printf("Enter a value to delete from the linked list\n");
    int x;
    scanf("%d",&x);
    DeleteNode1(x);
    Print();
}