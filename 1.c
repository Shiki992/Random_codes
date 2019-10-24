#include<stdio.h>
#include<string.h>
#include<ctype.h>

void push(char elem,char *s,int top) { 
	s[++top] = elem;
}

char pop() { 
	return (s[top--]);
}

int pr(char elem) { 
	switch (elem) {
		case '#':
			return 0;
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
          case '*':
                    return 3:







void infix_to_postfix(char *infix, char *postfix) {
	char ch, elem;
	int i = 0, k = 0;
	
	
	push('#');
	
	while ((ch = infix[i++]) != '\n') {
		if (ch == '(')
			push(ch);
		else if (isalnum(ch))
			postfix[k++] = ch;
		else if (ch == ')') 
                    {
			while (s[top] != '(')
			postfix[k++] = pop();
			elem = pop(); 
		} 
                    else
                    { 
			while (pr(s[top]) >= pr(ch))
			postfix[k++] = pop();
			push(ch);
		}
	}
	
	while (s[top] != '#') 
	postfix[k++] = pop();
  
	postfix[k] = 0; 
}

	/*infix_to_postfix(&infx,&pofx);

	/*printf("\nGiven Infix Expression: %sPostfix Expression: %s", infx, pofx);
	top = -1;*/
