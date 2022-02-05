#include<stdio.h>
#include<iostream>
int main(){
    int a;
    int *p;
    p = &a;
    // could alternatively do int *p = &a. Different from doing *p = 5;

    // each of these print a different pointer? I believe the first one casts it to an integer (decimal (base 10) numbers instead of hexadecimal)
    printf("%d\n", p);
    std::cout << p << "\n\n";
    

    int b;
    int *p1;
    p1 = &b;
    // these two values are garbage values, because the int was not initialized
    std::cout << *p << std::endl;
    std::cout << *p1 << "\n";


    p = &a; // &a = address of a
    *p = 12; // deferencing
    std::cout << a << "\n";
    b = 20;
    *p = b; // this will not change the address of p, but will make a equal to 20. Changing it to the address b would be doing p = &b
    std::cout << "value of a is " << a << std::endl;
    std::cout << "Value at p is " << *p << "\n\n";
    
    // Pointer arithmetic
    std::cout << "Pointer Arithmetic" << std::endl;
    std::cout << "Size of integer is: " << sizeof(int) << std::endl;
    std::cout << "Address p is: " << p << std::endl; // ex: p is 2002
    std::cout << "Address p+1 is: " << p+1 << std::endl; // then p+1 is 2006
    // This is because, this in an integer pointer, which takes 4 bytes (2002 to 2005).

    std::cout << "Address p+2 is: " << p+2 << std::endl; // then p+1 is 2006
    std::cout << &b << std::endl; // this is the address of b. notice that it doesn't directly move 1 up of the previous pointer for the next variable declared

    // trying out printf as well
    printf("value at address p+1 %d\n", *(p+1)); // garbage value since there is no integer allocated to this memory address
    // this is an issue we can run into with pointer manipulation. Try doing this with mix of data types or just other data types to see what happens
}