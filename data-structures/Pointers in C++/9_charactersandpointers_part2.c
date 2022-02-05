#include<stdio.h>
#include<string.h>

// start by recreating what was done in the previous part (lesson 8)
// When we say two variables have different scopes, this means that they are seen by different parts of the program
// For example, char *C's scope is local to the print function, whereas C[] is local to the main function

void print(const char *C)
{
    // C[0] = 'A'; // without the const, this will have an error for char* D.
    // We will now get an error for not obeying const if we make *C a constant

    while(*C != '\0')
    {
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main()
{
    char C[20] = "Hello"; // This will be stored in the Main stack frame
    print(C);
    char *D = "Hello"; // Here, on the other hand, the string gets stored as a compile time constant. 
    // This same thing happens when we pass a string literal to a function
    // It will most probably be stored in the "text" section of the application memory.
    // *** AND: it cannot be modified
    // C[0] = 'A'; // This results in an error.
    print(D); 
    // if we want a function to only read and not be able to write a certain data type, we use const (see the print method)


}