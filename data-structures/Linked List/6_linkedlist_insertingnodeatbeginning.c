
#include<stdio.h>
#include<stdlib.h>

// Linked List: Inserting a node at the beginning
// Question: would it be better to make a separate tail node, and make the final element's pointer point to the tail node. This may fix those issues
// that I had with printing.
// I believe that having a tail node is also better for Big O

struct Node
{
    int data;
    struct Node* next; // same as "link" in lesson 5
};

// If we made this a local variable in main, we would have to pass it as an argument into each function, and the functions changing head would have to return a Node pointer (Node*) as well
// Or, we could also make the parameter as a Node** which is a pointer to pointer, and then we would have to dereference using *head throughout. However, this would actually change head and we could keep the function as void.
// Review pointers again to see how the double pointer Node** in the commented line one above this line, would work exactly.
struct Node* head; // same as A in lesson 5

// function that will insert a node at the beginning of the linked list
void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); // in the video he didnt use struct node, did he switch to c++ mid video? But then again, why would he use malloc then?
    (*temp).data = x; // could also do temp->data = x;
    temp->next = head; // if the list is empty, then head will be null, making this new node point to null. However, if the head is pointing to a node, this new node will now point to that node
    // since head would be pointing to the first node, this means that this new node will now point to that node, since this new node is the first node
    head = temp; // now the pointer variable head points to the temp node. If we also did the if statement above, head will now point to this new node
    // At 6:42 in the video
}

// Interestingly, if I do void Print(); with that semicolon at the end, there doesn't appear to be errors, not sure if doing {} instead has any differences though.
void Print(){
    struct Node* temp = head;
    printf("Linked list: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
   
    head = NULL; // empty list
    
    // We have created a global variable, head, which is type: pointer to node
    // and the value in this pointer variable, is NULL. Meaning that so far, the list is empty

    // // Now we want to ask the user for numbers, and add them all to the linked list
    printf("How many numbers?\n");
    int n,i,x;
    
    scanf("%d", &n); // why do we do &n, I do not understand that.
    for(i=0; i<n; i++){
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print(); // This prints the entire linked list
    }
}
