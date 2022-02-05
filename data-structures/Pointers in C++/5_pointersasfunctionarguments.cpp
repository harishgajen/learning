#include<stdio.h>
// Pointers as function arguments - call by reference

void Increment(int a)
{
    a = a+1;
    printf("Address of variable a in increment = %d\n", &a);
}

void Increment(int* p)
{
    *p = (*p) + 1;
}


int main(){
    int a;
    a=10;
    Increment(a);
    printf("Address of variable a in main = %d\n", &a);
    // printf("%d\n", a);  the a in the function Increment is another a
    // notice the different addresses of a in the function vs the main

    // When a program or application starts, the machine reserves some amount of memory
    // for the execution for this program. One part of application's memory is the actual code(text).
    // The second part is for static/global variables. If not specified, they are global variables (MUST HAVE HEARD THIS PART WRONG. I THINK IT IS LOCAL BY DEFAULT).
    // The third part, a stack, is where all the local variables go. This is the main part of the lesson.
    // The fourth part, the heap, will be mentioned in the following lessons
    // The text, global variables (and static?? Probably), and stack segments are all fixed.
    // However, the application can keep asking for more memory for the heap segment during its execution

    /**
     * When a function is invoked, like the main method, all the info about the method call, like 
     * parameters, local variables, calling function to which it should return, the current instruction at which it is executing
     * is all stored in the stack. We will create a unit, called a stack frame, for each function. Main will have a stack frame.
     * When we call the Increment function, it will stop the execution of main at a particular instruction. Then add Increment to the stack.
     * It will return to main once Increment is done. 
     * Fresh local variables are created corresponding to the parameters of the new function.
     * Whatever parameters have been passed are copied to these variables.
     * This a which is local to the stack frame of Increment is incremented to become 11. We cannot access a variable outside the current stack frame.
     * When it returns to main, it clears the stack frame for Increment, and resumes with main
     * The lifetime of a local variable, is for the time that a function is executing.
     * printf even creates a stack. This is called a call stack. 
     * main is our calling function and Increment is the called function
     * a in main is the actual argument - a in Increment is a formal argument. 
     * a as an actual argument is mapped to a as a formal argument. 
     */

    // This is why Albert couldn't make local a in the main method to 11
    // We can achieve Albert's goal with pointers.

    Increment(&a);
    printf("%d\n", a);

    // Instead of passing the value of the variable, we pass the address of the variable, so that we have a reference to the variable
    // so that we can deference it and perform some operations, is called: 
    // call by reference

    // This can save us time, because instead of copying of a large and complex data type, if we just use a reference to it
    // it will cost us a lot less memory, and are saved from creating a new copy of a complex data type
}