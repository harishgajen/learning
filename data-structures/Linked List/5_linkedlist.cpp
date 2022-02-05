#include<stdio.h>
#include<stdlib.h> // what is the purpose of this one?

// Key takeaway(s):
// When we do head = temp (A = temp), this makes A the first element, and the head node.
// head returns a pointer to element 1
// So when we do head->data, it is checking the data of element 1

struct Node 
{
    int data;
    Node* link;
};

// we have created a pointer called A and this pointer points nowhere, so the list is empty
int main(){
    // This is the reference to the start of our linked list
    Node* A;
    A = NULL; 

    // **A is the HEAD Node, that simply points to the first node in the link, or is equal to NULL if the list is empty.

    // this is adding a new node to our linked list, effectively being the first one
    Node* temp = new Node(); // can still use malloc, but since new is an option in C++, it looks a lot cleaner and is recommended
    temp->data = 2; // (*temp).data = 2; also works
    temp->link = NULL; // (*temp).data = NULL; also works
    A = temp; // making the pointer A equal to the reference of temp
    
    // Now, what if we wanted to add two more nodes, for a total of 3.
    // We can actually use the same temp variable to create this new node, since the previous node is already linked
    // with the HEAD NODE
    temp = new Node();
    temp->data = 4;
    temp->link = NULL;

    // Next, we have to traverse the list to set the address of the previous node to the address of this new node
    // Ideally, this should be in a function, which we will do in the following lessons
    Node* temp1 = A;
    while(temp1->link != NULL){
        temp1 = temp1->link;
    }
    // we have now reached the previously added node
    temp1->link = temp;

    // now, lets print out the entire list
    temp1 = A;
    
    // This is the approach from video 6. The approach he showed in the written code in vid 5 was not working, because the head node is equal to temp, making it contain the same members
    temp1 = A;
    while(temp1 != NULL){
        printf("%d\n", temp1->data);
        temp1 = temp1->link;
    }
    printf("%d\n", &A); // this is the address of the head node
    printf("%d\n", A); // this is the address of node 1
    printf("%d\n", A->data); // A is the address of node1, so the data of that node is 2
    printf("%d\n", (A->link)->data); // prints 4

    // Find a way to test this theory. Still confused a bit. 



    // printf("%d\n", ((A->link)->link)->data); // Now, this becomes an error. I thought I had added 2 nodes though. Probably because A->link and the link of temp are the same. 
    // OH THE FIRST NODE IS THE HEAD NODE.
    // WE DID TEMP = A
    // This way, shown in video 5, will not work because, since A is equal to temp, it's data variable is set to the same as the temp. 
    // This is really interesting considering the concept of pointers. I have to review pointers to fully understand why the behaviour is like this. What is the point of having the head and first element both have a data variable?
    // temp1 = A;
    // while(temp1->link != NULL){
    //     temp1 = temp1->link;
    //     printf("%d\n", temp1->data);
        
    // }

}