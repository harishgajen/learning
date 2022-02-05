#include<stdio.h>
#include<string.h> // library for string manipulation (many functions for string manipulation
// This <string.h> library also assume that the string will be null terminated.

/* How to store strings
 * size of the char array must be >= number of characters +1
 * For example, "John", must go in a char array of at least size 5
 * In the index after the final character in the string, we put a null character, which is '\0'
 * This indicates that we have reached the end of the string.
 * So John takes up 4 characters, and the 5th one (at index 4) is used to have '\0' to indicate that index 3 is the end of the string
 /**/

// Rule: A string in C has to be null-terminated (explained above)

// the program reads char[] D as a parameter as char* D, since arrays are pass by reference
// As learned in the previous lesson, this function does not know the size of this array. 
// It simply knows the reference to the first element, and continues to do so until there is a null character.
// This is why, in the printf function, it prints garbage characters when you do printf of a string for an array of characters 
// that do not have a terminating null character.
void print(char* D)
{
    int i=0;
    while(D[i] != '\0'){
        printf("%c", D[i]);
        i++;
    }
    printf("\n");

    /**
     * We can also do:
     * while(*D != '\0'){
     * and then inside the loop do D++ instead of i++
     * This works because the pointer will be incremented by the size of the data type (in this case a character)
     * until the pointer points to a value that is equal to a null character.
     * This therefore has the same effect as what is done in the for loop that is actually in the function
     **/
}

int main()
{
    // probably a bad idea to name an array C, but just following the tutorial - wouldn't do that myself. 
    // Should look into whether or not that matters too. 
    char C[5]; // as long as the size if 5 or bigger, it will print fine.
    //THIS IS BECAUSE, PRINTF PRINTS UNTIL IT FINDS A NULL CHARACTER.
    C[0] = 'C';
    C[1] = 'H';
    C[2] = 'A';
    C[3] = 'D';
    C[4] = '\0';
    printf("%s\n", C);

    char test[4];
    test[0] = 'C';
    test[1] = 'H';
    test[2] = 'A';
    test[3] = 'D';
    printf("%s\n\n", test); // notice the strange characters at the end when the array is not null terminated

    int len = strlen(C);
    
    // You can also use: string literals - a group of characters within double quotation marks
    char name[] = "CHAD"; // the null termination for a string literal is implicit - it is always stored with a null termination in memory
    // Note: you cannot just declare and on another line do name = "HARISH";
    // You could also do char name[x], x being any number, but being >= + 1 the size of the string
    // When you just do name[] it will be n bytes long + 1, n being the number of letters plus the character for the terminating null character

    // char[4] = "JOHN";  See, this is an error because it needs to be 5 minimum for "JOHN"

    // will print 4 only, because it stops once there is a null character
    printf("Lenght A = %d\n", len); // 4
    printf("Length name = %d\n", strlen(name)); // 4

    // Could also do this, but need to follow all rules, including the terminating null character
    char name1[] = {'C', 'H', 'A', 'D', '\0'};
    printf("\n%s\n", name1);



    // Character arrays and pointers
    // Arrays and pointers are different types that are used in a similar manner.
    char C1[6] = "Hello";
    char* C2;
    C2 = C1; // now points to the first element of the array

    // we can now use this character pointer C2, to read and write to the array, just like C1
    printf("%c\n", C2[1]); // e
    C2[0] = 'A'; // "Aello"
    // C2[i] is *(C2+1)

    // Note: C2 = C1 is valid, but C1 = C2 is not valid
    // C1 = C1+1 is invalid because that is the array
    // C2++ is valid because it is incrementing the pointer by the size of the data type, in this case: a character

    // Arrays are always passed to function by reference
    char D[20] = "Hello";
    // Now, what if I wanted to use my own function to print D, instead of printf?
    print(D);
}