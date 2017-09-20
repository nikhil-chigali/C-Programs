//stack applications
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

char stack[20];
int top=-1,astack[20];

void push(int e)
{
	astack[++top]=e;
}

int pop()
{
	return astack[top--]; 
}

char chpop()
{
	return stack[top--];
}
void chpush(char e)
{
	stack[++top]=e;
}

int precedence(char e)
{
	if(e=='^')
	return 3;
	else if(e=='*'||e=='/')
	return 2;
	else if(e=='+'||e=='-')
	return 1;
	else return 0;
}

int main()
{
	char exp[20],e,temp;
	char pstfix[20];
	int i;
	printf("\nenter an infix expression\n");
	scanf("%s",exp);
	
	
	/*
		*****CHECKING IF THE INFIX EXP IS VALID OR NOT*****
	*/
	
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='['||exp[i]=='('||exp[i]=='{')
		{
			chpush(exp[i]);
		}
		else if(exp[i]==']')
		{
			if(chpop()!='[')
			{
				printf("\nERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		else if(exp[i]==')')
		{
			if(chpop()!='(')
			{
				printf("\nERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		else if(exp[i]=='}')
		{
			if(chpop()!='{')
			{
				printf("\nERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		
		
    }
    if(top!=-1)
    {
    	printf("\nERROR:INVALID EXPRESSION");
    	exit(0);
	}
	
  	/*
		*****CONVERTING INFIX EXP TO POSTFIX*****
	*/
	top=-1;
	int p=0;
		for(i=0;exp[i]!='\0';i++)
	{
		if(isdigit(exp[i]))
		{
		pstfix[p]=exp[i];p++;
		}
		else if(exp[i]=='(')
		{
			chpush(exp[i]);
		}
		else if(exp[i]=='{')
		{
			chpush(exp[i]);
		}
	    else if(exp[i]=='[')
		{
			chpush(exp[i]);
		}		
		else if(exp[i]==')')
		{
		
			while((temp=chpop())!='(')
			{
			
				pstfix[p]=temp;p++;
			}
		}
		else if(exp[i]=='}')
		{
		
			while((temp=chpop())!='{')
			{
			
				pstfix[p]=temp;p++;
			}
		}
		else if(exp[i]==']')
		{
		
			while((temp=chpop())!='[')
			{
			
				pstfix[p]=temp;p++;
			}
		}	
		else
		{
			if(precedence(exp[i])<=precedence(stack[top]))
			{
				pstfix[p]=chpop();p++;
				chpush(exp[i]);
			}
			else if(precedence(exp[i])>precedence(stack[top])){
				chpush(exp[i]);
			}
		}
		
	}
	while(top!=-1)
	{
		pstfix[p]=chpop();p++;
	}
	

	 /*
	 	*****EVALUATING POSTFIX EXPRESSION*****
	 */
	 
	top=-1;
	int op1,op2,result;
	for(i=0;pstfix[i]!='\0';i++)
	{
		e=pstfix[i];
		if(isdigit(e))
		{
			push(e-48);
		}
		else
		{   op2=pop();
			op1=pop();
			switch(e)
			{
				case '+':
					result=op1+op2;break;
				case '-':
					result=op1-op2;break;
				case '*':
					result=op1*op2;break;
				case '/':
					result=op1/op2;break;
				
			}
			push(result);
		}
	}
	printf("\nresult=%d ",astack[top]);




return 0;
}
	
