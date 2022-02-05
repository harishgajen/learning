#include<stdio.h>
#include<stdlib.h> // why is this second one needed?

/** Application's Memory
 * Code/text (instructions)
 * Static/global (variables that can be accessed throughout computation)
 * Stack (function calls, local variables)
 * The amount of memory set aside for these three segments, does not grow when the application is running
 * We will come back to the fourth section - heap - later in the lesson
 **/

// If I need a variable to be accessed in multiple stack frames, but not the entire program
// I can use heap. (If needed for the entire run time I could just use global/static)

// Also, the stack portion of memory is using the stack data structure, but
// heap memory does not use the heap data structure

// In C: malloc, calloc, realloc, free
// In C++: new, delete (in place for malloc and free, respectively)
int main()
{
    int a; // goes on stack
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 10;
    free(p);
    p = (int*)malloc(20*sizeof(int));
    p[0] = 5;
    *(p+2) = 6;

    /** In C++
     * int *p;
     * p = new int;
     * *p = 10;
     * delete p;
     * p = new int[20];
     * delete[] p;
     **/
    // In C++, we don't have to do type casting, like when malloc returns a void pointer and we have to cast it to an int pointer
    // This is because in C++, new and delete operators are type safe. This means, that they are used with a type, and return pointers to a particular type only
    // So, p will get an integer pointer only.
}