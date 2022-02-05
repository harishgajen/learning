// Iterative solution
// Time - O(n), Space - O(1)

// Recursive solution (Implicit stack)
// Time - O(n), Space - O(n) (maybe because we are creating the stack inside that function??)

// ^^^ Why exactly is the space complexity of the recursive solution O(n) while it is O(1) for iterative? What does implicit stack mean?? I'm guessing that is the implementation 
// done in the videos: "Reverse a linked list using recursion" and "Pointers and dynamic memory - stack vs heap"

// This solution uses an explicit stack

#include<stdio.h>
#include<stdlib.h>
#include<stack>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head; // should this go above functions or below, and does that impact functionality at all?

void Reverse()
{
    stack<Node*> S; // without namespace std, we would have to do std::stack<Node*> S;
    Node* temp = head;
    while(temp != NULL) {
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()) {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

// For inserting at the end (simplicity's sake)
void Insert(int x)
{
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    
    if(head == NULL) {
        head = temp;
        return;
    }

    Node* temp1 = head;
    while(temp1->next != NULL) 
    {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Print();
    Reverse();
    Print();
}