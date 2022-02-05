// By parentheses, we consider the following symbols: "(), {}, and []""
// As we scan left to right, any "closer" should be closing the previous unclosed parenthesis (LAST UNCLOSED, FIRST CLOSED)

/* 
    Solution:
    Scan from left to right.
    If opening symbol, add it to a list.
    If closing symbol, remove last opening symbol in list. 
    Should end with an empty list.
 */

// We can therefore use a stack here.
/* 
    Revised Rules:
    Scan from left to right
    If opening symbol, PUSH it into a STACK
    If closing symbol and top of stack opening of same type, POP
    Should end with an empty list
 */

#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>
using namespace std;

bool ArePair(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '[' && closing == ']') return true;
    else if(opening == '{' && closing == '}') return true;
    return false;
}

bool CheckBalancedParentheses(string exp) {
    stack<char> parentheses;
    int size = exp.length();
    for(int i=0; i<size; i++) {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{') parentheses.push(exp[i]);
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if(parentheses.empty() || !ArePair(parentheses.top(), exp[i])) return false;
            parentheses.pop();
        }
    }
    return parentheses.empty() ? true:false;
}

int main()
{
    string exp1 = ")(";
    string exp2 = "[(])";
    string exp3 = "{()()}";
    printf("%d\n", CheckBalancedParentheses(exp1));
    printf("%d\n", CheckBalancedParentheses(exp2));
    printf("%d\n", CheckBalancedParentheses(exp3));
}