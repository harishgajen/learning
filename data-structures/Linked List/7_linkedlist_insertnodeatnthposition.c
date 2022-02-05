#include<stdio.h>
#include<stdlib.h>

// Linked list: inserting a node at the nth position (pronounced: en-ith, not enth, at least according to this video. Logically, the way he pronounces it makes sense too)
// The video near the end has a good tracing and explanation of dynamic memory with linked lists
// and exactly how this program uses the stack, global, and heap memory.

// Remember how important it is that head is a global variable
// If it was not, we'd have to pass by value and return head back, or pass by reference to keep the function's void return type

// Assuming that first element is at 1th position
// Also, not accounting for invalid inputs, like an out of bounds position, for simplicity's sake

struct Node
{
    // the two fields of Node
    int data;
    struct Node* next;
};

struct Node* head; // Question: what would happen if I made it null here instead of at the beginning of main?

void Insert(int data, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node)); // temp1 is a pointer to the Node created in the heap
    temp1->data = data; // the data is saved in the heap in the block allocated for temp1
    temp1->next = NULL; // the next pointer is saved in the heap in the block allocated for temp1
    
    // this if statement covers the scenario of inserting at the beginning, and even for when the list is empty
    if(n==1) {
        temp1->next = head;
        head = temp1;
        return;
    }

    // Heap: No new memory is allocated in the heap for temp2, 
    // it simply points at other blocks in the heap. 
    // We know this because new and/or malloc are never used
    
    // here, we are iterating through the linked list. 
    struct Node* temp2 = head;
    int i;
    // Let's trace this for loop to understand what happens when inserting 5 as the second node
    // i=0 which is not less than n-2 (2-2=0) so we don't iterate even once through the loop
    // Now that we are out of the for loop, temp1's pointer becomes temp2s pointer
    // Since the list is currently 4,2,3 we know that temp2 (the head)'s next node is the second node
    // Now this new node will point to 2
    // Then, the head node (first node)'s next pointer will point to this new second node 
    
    // We do n-2, since we start at the head, which is the first node. The for loop starts at 0, even though that is node 1
    // If we did for(i=1), then it would make sense to do i<n
    for(i=0; i<n-2; i++) {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next; // This newly inserted node will now point to the what the node before it points to
    temp2->next = temp1; // The node before it will now point to this new node
    // Overall, the node before it will point to this newly added node, and the newly added node will point to the node that used to be in its position
    // Keep in mind, this is only when the node is not being inserted at the beginning/this is only when the list is not empty

}

// Each time the function's execution has finished, all the local variables are gone from the memory
void Print() 
{
    struct Node* temp = head;     
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL; // empty list
    Insert(2, 1); // List: 2
    Insert(3, 2); // List: 2,3
    Insert(4, 1); // 4,2,3
    Insert(5, 2); // List: 4,5,2,3
    Print();
}