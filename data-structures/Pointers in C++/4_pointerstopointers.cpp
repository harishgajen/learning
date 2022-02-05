#include<stdio.h>

int main(){
    int x = 5; // allocates 4 bytes for x
    int *p; // reserves 4 bytes for this pointer (4 bytes since it is an integer pointer)
    p = &x; // p now points to x. If p and x were different types, this would not be a valid statement
    *p = 6;

    // now, what if we wanted a pointer for the pointer p?
    int **q; // this can store the address of an integer pointer
    q = &p; // q now points to p
    
    // can also put the asterisks like this, it does not matter if it is in front of the data type
    // or if is behind the variable name of the pointer
    int*** r; // pointer to a pointer to a pointer of an integer
    r = &q;
    // these two lines above could be done together as int*** r = &q;

    // now, write what the output should be as a comment beside each line
    printf("%d\n", *p); // 6
    printf("%d\n", *q); // 225 (the value of p (in the example), since p is set to the address of x)
    printf("%d\n", *(*q)); // the value of the pointer at *q, which is the value at x which is 6
    printf("%d\n", **q); // this also works, but it is good practice to use parentheses like how they are used above, because of how precedence works when we use other operators
    printf("%d\n", *(*r)); // dereferencing will take us all the way to 225. 225 (the value of p, which is the address of x)
    printf("%d\n", *(*(*r))); // 6 dereferencing will take us all the way to 6

    ***r = 10;
    printf("x = %d\n", x);
    **q = *p+2; // 12. we are dereferencing here. *p = 10 so it will become 12

    // is it only dereferencing when you reach the actual value at the end? Probably not, but worth looking into. 
}