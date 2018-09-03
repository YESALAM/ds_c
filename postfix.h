#include <string.h>

#include "stack.h"
#include "helpers.h"

 
 
int infixToPostfix(char* exp)
{
    int i, k;
 
    
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) 
        return -1 ;
 
    char last_character ;
    for (i = 0, k = -1; exp[i]; ++i)
    {
        
        
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        
        else if (exp[i] == '(')
            push(stack, exp[i]);
         
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression             
            else
                pop(stack);
        }
        else // an operator is encountered
        {   
            if(i==0 || exp[i-1]=='(' || peek(stack)==exp[i-1]){//this is a unary operator
                if(exp[i]=='+'){
                    continue ;//do nothins as it does not affect the value
                }else if(exp[i]=='-'){
                    exp[++k] = '$';
                    continue;
                }
            }

            while (!isEmpty(stack) && getPriority(exp[i]) <= getPriority(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
 
    }
 
    
    while (!isEmpty(stack))
        exp[++k] = pop(stack );
 
    exp[++k] = '\0';
   
}
