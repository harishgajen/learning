#include<stdio.h>

int main()
{
    int A[] = {5, 2, 3, 4, 5};

    int* p = A;
    printf("%d\n", p); // the reference of A[0]
    printf("%d\n", *p); // value of A[0]: 5
    printf("%d\n", *(p+2)); // value of A[2]: 3
    // *(p+2) will be 8 bytes ahead in the memory of p, because it essential does
    // p + (2 * size of data type). Since it is int, that is 4

    // Review:
    // *(A+i) is same is A[i]
    // (A+i) is the same as &A[i]

    // However, it is important to note some differences
    // p = A is valid, but A=p is invalid

    // Now, onto multi-dimensional arrays (here, we do 2d arrays)
    int B[2][3]; 
    // B[0], B[1] are 1-d arrays of 3 integers each
    // Remember, the name of the array returns a pointer to the first element in the array
    // However, this time, each element is a 1d array of 3 integers
    
    // int *p0 = B; // this will give an error because it will return a pointer to 1d array of 3 integers
    
    // **** The type of a pointer doesn't matter when you are reading an address, but it does
    // **** when you dereference, or when you perform pointer arithmetic

    // Instead of int *p0 = B;.we should do this:
    int (*p1)[3] = B;

    printf("\n%d %d\n", B, &B[0]); // Both will print the address of the base reference in the array
    printf("%d %d\n", *B, B[0]); // These will also print the address of the first byte in the first block of B
    // This is because the value at B (*B) is the pointer to the first element in the array at B[0]
    // And B[0] does the same thing, pointing to the first element in the array at B[0]

    printf("%d %d\n", B+1, &B[1]); // These both are the reference to the second elemenet in B, which will therefore point to the second array of three integers
    // This will be 12 bytes ahead of what was printed above, because each array at the elements inside B are 3 integers (3x4 = 12)

    // Now, we are going to dereference. This is where the type of pointer becomes important:
    printf("%d\n", *(B+1), B[1], &B[1][0]); // This should give the pointer to the first integer in the array at B[1]c

    printf("%d\n", *(B+1) + 2); // First, *(B+!) will get the integer pointer of the array at B[1]. 
    // Then, since this is an integer pointer, the +2 will increment that value by 8, since the data type is integer (2x4 = 8)
    // This is pointer arithmetic
    // In the video example, the address printed out would be 420
    
    // These do the same thing, they are simply alternate syntax
    printf("%d\n", B[1] + 2);
    printf("%d\n", &B[1][2]);


    B[0][1] = 545;
    printf("%d\n", *(*B+1)); 
    // Breakdown of the line above
    // *B: B -> int(*)[3]
    // *B returns B[0]
    // B[0] is an integer pointer (for example: address 400)
    // When you try to add 1 to an integer pointer, it adds 4 bytes, making it address (404)
    // Then the * on the outside will get the value at this address
    // This is effectively the same as B[0][1]

    /** For a 2-D array:
     * B[i][j] = *(B[i]+j)
     * B[i][j] = *(*(B+)+j)
     **/
    
    // Extra testing:
    // If I do &B[1] + 2, what is that doing exactly?
}