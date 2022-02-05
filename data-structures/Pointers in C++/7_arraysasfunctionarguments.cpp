#include<stdio.h>

int SumOfElements(int A[], int size)
{
    int sum=0;
    for(int i=0; i<size; i++){
        sum += A[i];
    }
    return sum;
}

int SumOfElements(int A[])
{
    int sum=0;
    int size = sizeof(A)/sizeof(A[0]);
    printf("SumOfElements - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for(int i=0; i<size; i++){
        sum += A[i];
    }
    return sum;
}

// SOE is short for SumOfElements
int NewSOE(int* A, int size){
    int sum=0;
    for(int i=0; i<size; i++){
        sum += A[i]; // A[i] is *(A+1) -> sum += *(A+i); would also work
        
    }
    return sum;
}

void Double(int* A, int size){
    for(int i=0; i<size; i++) {
        A[i] *= 2;
    }
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    int total = SumOfElements(A, size);
    printf("%d\n", total); 

    // what if we wanted to find the size of the array inside the function SumOfElements:

    int total1 = SumOfElements(A);
    printf("%d\n", total1);

    // total and total1 are different answers

    printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));

    // the size of A in the function SumOfElements (SOE) is calculated to be 4
    
    // 20 bytes are allocated for array A in the stack frame for Main
    // 4 bytes for the total variable that we made. 

    // Another 4 bytes are allocated for total1
    // When we make a function call for SumOfElements(A); ideally, we should have A copied from the calling function
    // main, into the called function SumOfElements

    // ***THIS ACTUALLY DOES NOT HAPPEN
    // When a function sees an array as a function's argument, it does not copy the array, it just creates a pointer variable of the same name
    // and points to the first element in the array
    // The compiler implicitly converts int A[] to int* A
    // This means that arrays are always called by reference.
    // This is why, when we do sizeof(A), it gives 4 bytes, because it is just an integer pointer
    // This means that we actually have to pass the size to the function

    int total3 = NewSOE(A, size); 
    printf("%d\n", total3);
    int total4 = NewSOE(&A[0], size);
    printf("%d\n", total4);

    // It is important to note, since we passed A instead of &A[0] instead of a pointer variable,
    // we cannot do something like p++
    // The advantage is doing A[i], though.

    // Since arrays are passed by reference, we can modify the elements of the array in the called function, and it would
    // reflect that in the calling function
    printf("\nBefore doubling\n");
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }
    printf("\n%After doubling\n");

    // notice how this function was able to actually change the values in the array
    Double(A, size);
    for(int i=0; i<size; i++){
        printf("%d ", A[i]);
    }

    // An important use case of arrays as function arguments, is when we work with strings in C
    // Strings is C are nothing but character arrays. This concept really becomes important in the context of character arrays.
}