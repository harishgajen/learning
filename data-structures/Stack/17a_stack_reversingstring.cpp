// NOTE: UNCOMMENT THE gets(C); line. I commented it to avoid the error mark from vsc

#include<iostream>
#include<cstring>
#include<stack> // stack from standard template library (STL)
using namespace std;

// Here we are also using the C++ implementation of a stack
// Here, it is an array implementation, but it could also be a stack.
// C++'s libraries also give us their implementation of Stack.
// While we could use this class, we could also use #include<stack> which imports stack from the standard template library (STL) of C++ (seen above)
// class Stack
// {
//     private:
//         char A[101];
//         int top;
//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool isEmpty();
// };

// Time complexity is O(n) because the for loop iterations is proportional to n
// Space complexity is also O(n). Extra space taken is directly proportional to n (the stack).
// A more space efficient way of doing this would be, having a variable i at beginning index and a variable j at the last index, and switch them, then
// increment i and decrement j. This has a space complexity of O(1) because there is a constant amount of space taken. Time complexity would remain as O(n) for this method
// aswell though.
void Reverse(char *C, int n) { //  the char *C is how the compiler would interpret char C[] anyhow
    stack<char> S; // this creates a stack of characters
    // loop for push
    for(int i=0; i<n; i++) {
        S.push(C[i]);
    }
    // loop for pop
    for(int i=0; i<n; i++) {
        C[i] = S.top();
        S.pop();
    }

}

int main()
{
    char C[51];
    printf("Enter a string: ");
    //gets(C); // gets reads until the end of file (I even believe it reads through multiple lines) | Why is this marked as an error even though it works?
    Reverse(C, strlen(C));
    printf("Output = %s", C);
}
