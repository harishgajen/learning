#include<stdio.h>

// A common error is people doing **A for a 2d array and 
// ***A for 3d array
// but now we know, this simply wouldn't work or make sense.


// Remember, int A[] is the same as int *A for function parameters
// because the program never actually copies the array
void Func(int *A)
{

}

// Could I change this to (*B)[3]??
void Func(int B[][3])
{

}

void Func(int (*A)[3][3]) // Argument: 3-D array of integers
{

}

int main()
{
    // Review from previous lesson (lesson 10)
    int B[2][3];
    int (*p)[3] = B; // (*p)[3] declares a pointer to 1-d array of 3 integers
    printf("%d\n", p);
    
    // These each increase by 12, because it knows that the pointer is to a 1d array of 3 integers, so each time
    // we do +1 or ++, it increments by 12 beacuse (3x4 = 12)
    printf("%d\n", p+1);
    // p++; // set this to a comment because I want p to be correct for the rest of the program
    // printf("%d\n", p);

    // The following would give a warning and is wrong, because when we increment the pointer
    // B will not return a pointer to integer, it will return a pointer to a 1 dimensional array of 3 integers
    // It increments by 4 
    // int *p0 = B; 
    // printf("%d\n", p0);
    // printf("%d\n", p0 + 1);


    // Now, to the new lesson
    // Should add stuff up to 12:31 of the video

    // Now, onto 3d arrays
    // What if it was [3][2][4]
    int C[3][2][2] ={{{2,5},{7,9}},
                     {{3,4},{6,1}},
                     {{0,8},{11,13}}};
    printf("\n%d %d %d %d", C, *C, C[1], &C[0][0]);
    // The output for all these 4 expressions are the same. BUT WHY?
    // 1. C 
    // 2. *C will be
    // 3. C[1] will be
    // 4. &C[0][0] will be 

    printf("%d\n", *(C[0][0]+1)); // This is dereferencing the element at the address of
    // C[0][0] + 1. C[0][0] will be an integer pointer, so +1 will add 4 bytes
    // This will effectively then print the same as C[0][0][1]
    // This will therefore print 5

    // Add all the expressions shown in the video before the example above.
    // Rewatch the 10th video as well to fully understand
    // Even rewatch the array basics with pointers

    int A[2] = {1,2};
    int B[2][3] = {{2,4,6},{5,7,8}}; // B returns int(*)[3]
    Func(A); // A returns int*

    // To pass B into Func, we have to make the parameter int A[][3]
    Func(B);
    // Now, although this would work for B, it will not work for a 2d array with a different size for the 2nd dimension
    int X[2][4];
    // Func(X) would be an error because X returns int (*)[4]

    // To pass C from earlier, we need to make a 3rd type of function with new parameters
}