#include <stdio.h>
#include <string.h>
#include <math.h>

#include "stack.h"

int isDigit(char c){
    if (c>46 && c<58){
        return 1;
    }
    return 0;
}

int main(){
    

    char postfix[] = "5 4 + -543 +";
    int l = strlen(postfix);
    struct Stack* stack = createStack(l);
    
    char * rest = postfix ;
    char * token;
    while((token = strtok_r(rest," ", &rest))){
        int l = strlen(token);
        printf("%s\n",token);
        if(l==1 && !isDigit(token[0])){
            //operator found 
            //do the operation
            int value1 = pop_int(stack);
            int value2 = pop_int(stack);
            printf("%d %s %d\n",value1,token,value2);

            switch(token[0])
            {
                case '+': push_int(stack,value1+value2);break;
                case '-': push_int(stack,value2-value1);break;
                case '*': push_int(stack,value1*value2);break;
                case '/': push_int(stack,value2/value1);break;
                case '^': push_int(stack,pow(value1,value2));break;                    
            }            
        }else {
            //operand found
            //Push to stack
            int value = atoi(token);
            push_int(stack,value);
        }
        //advance to next token
        token = strtok(NULL, "-");
    }

    int result = pop_int(stack);
    printf("%d\n",result);
    return 0;
}





