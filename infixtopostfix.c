#include <stdio.h>


#include "postfix.h"

 
int main()
{
    char exp[] = "-a+b*(c^d-e)^(-f+g*h)-i";
    infixToPostfix(exp);
    printf( "%s\n", exp );
    return 0;
}

