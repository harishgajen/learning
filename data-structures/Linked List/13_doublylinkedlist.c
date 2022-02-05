#include<stdio.h>
#include<stdlib.h>

// Linked list: doubly linked list and inserting at head and tail
// Printing forward and reverse is good practice to see if both the next and prev pointer to Node's respectively are done correctly when inserting new nodes
// *** Note: Lesson 12 was just a concept/theoretical video, which is why there is no file to go with that lesson.

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head; // Global variable - pointer to head node

// Creating this separate function prevents duplicate code since we will have this in the InsertAtHead function and the InsertAtTail function, and the code will
// be a lot cleaner if we simply use this function instead
struct Node* GetNewNode(int x) {
    // Creating a node in the heap (dynamic memory), that can be referenced through a variable, which is the pointer to node variable: newNode
    // Remember, that while it is called heap, it is not an actual integration of heap in the memory, while it is for the stack section of the memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //Note, we can actually do something like struct Node myNode, and use the dot like with objects, but then it would just be a local node. By making a pointer variable and creating a new node,
    // the pointer is a local variable to the function, but the Node created will stay in the heap.
    
    newNode->data = x; // Alternate: (*temp).data = x | this dereferences the data structure and then can use it like a data structure with a dot
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// If we had for example, kept the same return type, and created a struct Node newNode (instead of Node*), and then return &newNode, even though
// we return the pointer variable, it is pointing to an address that was used during the run time of this function call.
// Since that function call has ended though, it is cleared from the stack and will not be remembered.
// This is why we use the memory on heap
void InsertAtHead(int x) {
    // Note: newNode is local to the function InsertAtHead, whereas the node created and returned from GetNewNode is stored in the heap
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    
    // This prevents the need for making head a separate local pointer to node variable
    head->prev = newNode; // Since the head node is going to be pushed to the second node and newNode will become the new head node, we set this old node's prev to the new Node that will be behind it
    newNode->next = head; // This new Node that will become the head should have it's next pointer be pointing to the current head node, which will become the second node
    head = newNode; // Now, the head pointer to Node will point to the new head Node: newNode
}
void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    
    // if list is empty
    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    
}
void Print() {
    struct Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    printf("Forward: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Would it not be faster to have a tail pointer to node, to avoid the first while loop entirely?
void ReversePrint() {
    struct Node* temp = head;
    if(temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse: ");
    // Traversing backward using prev pointer
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    head = NULL; // don't need to allocate memory on heap for a NULL pointer (that would be a waste of memory)
    
    // Could even do without the spaces between the function calls (start the next one right after the semicolon without the space), but that may be bad practice
    // In fact, having 3 commands on the same line may already be bad practice, but I'm not entirely sure. 
    InsertAtHead(6); Print(); ReversePrint();
    InsertAtHead(4); Print(); ReversePrint();
    InsertAtHead(2); Print(); ReversePrint();
    InsertAtTail(8); Print(); ReversePrint();
}