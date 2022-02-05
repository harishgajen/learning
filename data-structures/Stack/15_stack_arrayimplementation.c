#include<stdio.h>
#define MAX_SIZE 101 // this is a macro

/* 
    Stack: Array implementation
    Note: this is the not an ideal implementation. An ideal implementation would have a data type called stack, and we should be able to create instances of it.
    We can easily do it in an object oriented implementation. We can do it in C also, using structures. 
 */

// Pre-increment: ++i, will return the value of i after being incremented
// Post-increment: i++, will return the current value of i, and then will increment i, but that is not the value that is returned

// Since we are making these global variables, they will not need to be passed as function arguments
int A[MAX_SIZE];
int top = -1;


/* Note: Shift + alt + A for multiline comments
This will all be commented now
Add notes regarding the lesson here.
 */

void Push(int x) {
        // Handling overflow. We will have an overflow when the top index is equal to MAX_SIZE - 1, which is the highest index available in the array. 
        // In case of an overflow, we return this error message and return to handle the overflow:
        if(top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        return;
    }

    A[++top] = x; // the pre-increment will ensure that it increments top and also is that new value
}

// *******Since the return type is int, we can't have a special case to exit out of the function if the stack is empty. In this case, in the main, this function should only
// *******be called if the stack is not empty
// In the video he just did top-- and kept return type as void, but this was the suggested way online.
// What happens if we try to print and we get the if(top == -1) return? What value would it give?
int Pop() {
    return A[top--]; // post-decrement, so it returns the current top, and then does top-- afterwards.
}

int Top() {
    return A[top];
}

// Something about boolean in C. There is more to it. So, I am simply using 1 for true and 0 for false
int IsEmpty() {
    if(top == -1) return 1;
    return 0;
}

// Print function is not a typical operation avaiable with stack; we are only writing it here to test our implementation.
void Print() {
    int i;
    for(i = 0; i<=top; i++) 
        printf("%d ", A[i]);
    printf("\n");
}


int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    if(IsEmpty() == 0) printf("%d\n", Top());
}  