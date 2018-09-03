#include <stdio.h>
#include <math.h>

#include "stack.h"

int main(){
    //int count = 0;
    int n ;
    char from,to,aux,address,temp;

    struct Stack* n_stack = createStack(pow(2,n));
    struct Stack* from_stack = createStack(pow(2,n));
    struct Stack* to_stack = createStack(pow(2,n));
    struct Stack* aux_stack = createStack(pow(2,n));
    struct Stack* address_stack = createStack(pow(2,n));

    n=4 ;
    from = 'A';to='B',aux = 'C';address= 'S';
    push(address_stack,address);// S --> denotes starting of function
    push(n_stack,n);
    push(from_stack,from);
    push(to_stack,to);
    push(aux_stack,aux);

toh:    if(n==1){
            printf("disk %d %c --> %c\n",n,from,to);
            goto oneStepBack;
        }
        
        

        n = n-1;
        from = from;
        temp = to;
        to = aux;
        aux = temp;
        address = 'A';
        push(address_stack,address);
        push(n_stack,n);
        push(from_stack,from);
        push(to_stack,to);
        push(aux_stack,aux);
        goto toh;

B:      n = peek(n_stack);
        from = peek(from_stack);
        to = peek(to_stack);
        aux = peek(aux_stack);
        printf("disk %d %c --> %c\n",n,from,to);

        n=n-1;
        temp = from;
        from = aux;
        to = to;
        aux = temp;
        address = 'B';
        push(address_stack,address);
        push(n_stack,n);
        push(from_stack,from);
        push(to_stack,to);
        push(aux_stack,aux);
        goto toh;

oneStepBack:    
        
        pop(n_stack);
        pop(from_stack);
        pop(to_stack);
        pop(aux_stack);
        
        

        address = pop(address_stack);
        if(address == 'B' ) goto oneStepBack;
        else if (address == 'A') goto B;

        return 0;

}