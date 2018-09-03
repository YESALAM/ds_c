#include <stdio.h>

int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int getPriority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}

void reverseString(char* str){
    int l = strlen(str);
    int m = l/2;
    for(int i=0;i<m-1;i++){
        char tmp = str[i];
        str[i] = str[l-i-1];
        str[l-i-1] = tmp ;
    }
}
