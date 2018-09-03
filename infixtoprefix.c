
#include <stdio.h>
#include <stdlib.h>

#include "postfix.h"

void infixToPrefix(char* infix)
{
	/* Reverse String
	* Replace ( with ) and vice versa
	* Get Postfix
	* Reverse Postfix * */
	int l = strlen(infix);

	// Reverse infix
	reverseString(infix);

	// Replace ( with ) and vice versa
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}

	infixToPostfix(infix);

	// Reverse postfix
	reverseString(infix);

	
}

// Driver code
int main()
{
	char s[] = "(a-b/c)*(a/k-l)";
	infixToPrefix(s);
    printf("%s\n",s);
	return 0;
}
