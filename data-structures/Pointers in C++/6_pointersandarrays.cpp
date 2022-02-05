#include<stdio.h>

int main(){
    int A[5];
    printf("%d\n", (sizeof(A)/sizeof(A[0]))); // this is how we can get the size of the array (20 bytes / 4 bytes per integer = 5)
    printf("%d\n", sizeof(A)); // 20 because 5 elements x 4 bytes per integer element is a total of 20 bytes

    // side-note: why is this possible?
    int b[] = {5, 4, 3, 2};
    b[4] = 5;

    // both of these are ways to get the pointer to the base of the array (first element, index 0)
    int *p = A;
    int *p0 = &A[0];

    printf("Current p: %d\n", p);

    // A++; invalid
    p++; // valid (incremenets by 4 bytes, since that the data type for the pointer, int, is 4 bytes each)
    printf("New p: %d\n", p);

    int size = sizeof(A)/sizeof(int); // divisor should typically be sizeof(A[0]) instead of just the data type (int)
    for(int i=0; i<size; i++){
        // both do the same
        printf("Address: %d\n", (A+i));
        printf("Address %d\n", &A[i]);

        // both do the same
        printf("Value: %d\n", *(A+i));
        printf("Value: %d\n", A[i]); // *A[i] would be invalid
    }
    
}
