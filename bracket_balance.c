#include <stdio.h>
#include <string.h>
#include "stack.h"
 
// function to check if paranthesis are balanced
int areParanthesisBalanced(char * expr)
{
    struct Stack* s = createStack(strlen(expr));
    int l = strlen(expr);
    char x;
 
    // Traversing the Expression
    for (int i=0; i<l; i++)
    {
        if (expr[i]=='('||expr[i]=='['||expr[i]=='{')
        {
            // Push the element in the stack
            push(s,expr[i]);
            continue;
        }
        if (expr[i]!=')' && expr[i]!=']' && expr[i]!='}')
            continue;
 
        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (isEmpty(s))
           return 0;
 
        switch (expr[i])
        {
        case ')':
 
            // Store the top element in a
            x = pop(s);
            if (x=='{' || x=='[')
                return 0;
            break;
 
        case '}':
 
            // Store the top element in b
            x = pop(s);
            if (x=='(' || x=='[')
                return 0;
            break;
 
        case ']':
 
            // Store the top element in c
            x = pop(s);
            if (x =='(' || x == '{')
                return 0;
            break;
        }
    }
 
    // Check Empty Stack
    return (isEmpty(s));
}
 
// Driver program to test above function
int main()
{
    char expr[] = "{()[]";
 
    if (areParanthesisBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
