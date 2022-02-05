#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data; // if we wanted a different data type, we could simply change that here
    struct Node* link;
};

int main()
{
    struct Node* A;
    A = NULL; // empty list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    (*temp).data = 2;
    temp->data = 2; // this also works

    (*temp).link = NULL;
    temp->link = NULL; // this also works
    A = temp;

    // Now, what if we wanted to add two more nodes, for a total of 3.
    // We can actually use the same temp variable to create this new node, since the previous node is already linked
    // with the HEAD NODE
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = 4;
    temp->link = NULL;

    // Next, we have to traverse the list to set the address of the previous node to the address of this new node
    // Ideally, this should be in a function, which we will do in the following lessons
    struct Node* temp1 = A;
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

    printf("%d\n", A->data); // prints 2
    printf("%d\n", (A->link)->data); // prints 4
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

