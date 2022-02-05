#include<stdio.h>

int main(){
    // pointer variables are strongly typed
    // you need a pointer variable of a particular type, to store the address of a particular type of variable
    // int* -> int
    // char* -> char
    // user defined structure/type* -> user defined structure/type

    // their type is strongly/strong because we dereference to access/modify value
    // for example, when dereferencing an int, the int* pointer will let it know to check for the starting pointer byte plus the following 3 bytes
    // (total of 4 bytes)

    int a = 1025;
    int *p = &a;
    printf("size of integer is %d\n", sizeof(int));
    printf("Address = %x, value = %d\n", p, *p); // use %d for the address to get it in decimal instead of hexadecimal
    printf("Address = %d, value = %d\n", p, *p);
    
    char *p0 = (char*)p; // casting p to a character pointer
    printf("size of char is %d\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0); // notice how we only get the first digit of 1025 (value of the first byte of the int)
    printf("Address = %d, value = %d\n", p0+1, *(p0+1)); // in binary 00000100 is 4
    // 1025 = 00000000 00000000 00000100 00000001 -> p0 gets that first byte 00000001 since characters are only 1 byte

    // Void pointer - Generic pointer
    void *p2 = p; // no casting is needed.
    // since void pointer type is not mapped to a particular data type, we cannot dereference this pointer variable
    printf("Address = %d\n", p2);
    // cannot do pointer arithmetic because, again, it is not mapped to a particular data type.
}