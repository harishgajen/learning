#include <iostream>
using namespace std;
#define MAX_SIZE 101

/* 
    There were some arguments on the gist where I got this code from (mycodeschool's gist). Arguing about using #include<stdio.h> as well.
    Also, there were questions about switching the pop to an int return type an dreturning A[top--], which would do post-decrementation of returning the value of the element to
    be popped and then decrementing it. However, what would happen if we tried to print what gets returned, and then what returns is simply return; since
    there is that special case for if the stack is already empty?
 */

class Stack
{
    private:
        int A[MAX_SIZE];
        int top;

    public:
        Stack()
        {
            top = -1;
        }

        void Push(int x) {
            if(top == MAX_SIZE-1) {
                printf("Error: stack overflow\n");
                return;
            }
            A[++top] = x;
        }

        
        void Pop()
        {
            if(top == -1) {
                printf("Error: No element to pop\n");
                return;
            }
        }

        // *******Since the return type is int, we can't have a special case to exit out of the function if the stack is empty. In this case, in the main, this function should only
        // *******be called if the stack is not empty
        int Top()
        {
            return A[top];
        }

        // Why isn't this a boolean?
        int IsEmpty()
        {
            if(top == -1) return 1;
            return 0;
        }

        // This is only for testing,a nd is not a valid operation with stack - My guess: this is because in a stack you are only supposed to access the top element
        void Print() {
            printf("Stack: ");
            for(int i=0; i<=top; i++) 
                printf("%d ", A[i]);
            printf("\n");
        }
};

int main()
{
    Stack S;
    S.Push(2); 
    S.Print();
    S.Push(5); 
    S.Print();
    S.Push(10); 
    S.Print();
    S.Pop(); 
    S.Print();
    S.Push(12); 
    S.Print();
    if(!S.IsEmpty() == 0) printf("%d\n", S.Top());
}