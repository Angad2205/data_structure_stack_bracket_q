//bracket question
#include<stdio.h>    // headers are correct 
#include<string.h>
#include<stdlib.h>
#define size 30
struct stack {
	char Array[size]; 
	int top;
};
void init (stack *); // to initialize the stack
void push (stack * , char); // to put the data in the stack 
char pop (stack *); // to remove the data from the stack 
int match (char , stack *); //  used for matching the pairs 
int main ()
{int i = 0;
stack s1;
init(&s1);
stack *p = &s1;
char array[] = "[2*{(3-1)/5+7}-4]";
while (array[i] != '\0')
{
if (array[i] == '(' || array[i] == '{' || array[i] == '[')	
{
	push(&s1,array[i]);
}
else if (array[i] == ')' || array[i] == '}' || array[i] == ']')
{
	if (p->top == -1)
	{
		printf("the format is wrong 980");
		return 4;
	}
	if (match(array[i],p) == 1)
	{
		pop(&s1);  // matching should be there 
	}	
}

i++;
}
if (p->top == -1)
{
	printf("the entererd expression is correct");
}
else {
	printf("the Entered expression is not correct");
}
return 0;
}


void init (stack *sp)
{
	sp->top = -1;
}


void push (stack *sp , char data)
{
	if (sp->top  == size-1) //condition for stack overflow
	{
	printf("stack over flow");
	return ;
	}
		sp->top++;
		sp->Array[sp->top] = data;
	
}


char pop (stack *sp)
{ char value;
	if (sp->top == -1) // condition for stack under flow 
	{
		printf("Stack under flow");
		return ' ';
	}
	else {
	value = sp->Array[sp->top];
    sp->top--;
    return value;
	}
}
int match(char data1 , stack *s)   // here pointer is used to access the data for the comparision 
{ 
switch(data1)
{ 
case '}' :
	if (s->Array[s->top] == '{')
	{
	return 1;
	}
	else
	{
		return 0;
	}
	break;
	
	
case ']' :
	if (s->Array[s->top] == '[')
	{
	return 1;
	}
	else
	{
		return 0;
	}
		break;
		
		
		case ')' :
	if (s->Array[s->top] == '(')
	{
	return 1;
	}
	else
	{
		return 0;
	}
		break;
		
		
		default :
			return 0;
}
}
