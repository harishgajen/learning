#include<iostream>
// #include<stdio.h> he used this in video, but why? I think this uses printf

int main(){
    // note: the pointer to a certain data type must be in that same data type
    // for example: a char's pointer will also be a char

    int a = 5;
    int *point = &a;
    std::cout << point << std::endl; // prints the address
    std::cout << a << std::endl;
    std::cout << *point << "\n\n"; // prints the value at the address

    *point = 4; // changing the value at the value of the pointer to 4 (used to be 5)
    int b = 4;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << (a==b) << std::endl; // put the comparison in brackets to avoid error

}