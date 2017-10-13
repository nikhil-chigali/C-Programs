/*
	
	This header file converts any infix expression to postfix

*/

#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

#ifndef inffpstt   

/*

	pass the infix expression as a string and also an empty string  
	The resultant postfix expression will be copied to that empty string

*/

/*
	function ADTs
*/
void pusH(int e);
int PoP();
char chPoP();
void chPusH(char e);
int precedence(char e);
void convert(char* exp , char* pstfix);


/*
	End of ADTs
*/
char staCK[20];
int TOPP=-1,aStaCk[20];

void pusH(int e)
{
	aStaCk[++TOPP]=e;
}

int PoP()
{
	return aStaCk[TOPP--]; 
}

char chPoP()
{
	return staCK[TOPP--];
}
void chPusH(char e)
{
	staCK[++TOPP]=e;
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

void convert(char* exp , char* pstfix){
	
	
	char e,temp;
	int i;

	/*
		*****CHECKING IF THE INFIX EXP IS VALID OR NOT*****
	*/
	
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='['||exp[i]=='('||exp[i]=='{')
		{
			chPusH(exp[i]);
		}
		else if(exp[i]==']')
		{
			if(chPoP()!='[')
			{
				printf("ERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		else if(exp[i]==')')
		{
			if(chPoP()!='(')
			{
				printf("ERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		else if(exp[i]=='}')
		{
			if(chPoP()!='{')
			{
				printf("ERROR:INVALID EXPRESSION");
				exit(0);
			}	
		}
		
		
    }
    if(TOPP!=-1)
    {
    	printf("ERROR:INVALID EXPRESSION");
    	exit(0);
	}
	
	/*
		*****CONVERTING INFIX EXP TO POSTFIX*****
	*/
	TOPP=-1;
	int p=0;
	for(i=0;exp[i]!='\0';i++)
	{
		if(isdigit(exp[i]))
		{
		pstfix[p]=exp[i];p++;
		}
		else if(exp[i]=='(')
		{
			chPusH(exp[i]);
		}
		else if(exp[i]=='{')
		{
			chPusH(exp[i]);
		}
	    else if(exp[i]=='[')
		{
			chPusH(exp[i]);
		}		
		else if(exp[i]==')')
		{
		
			while((temp=chPoP())!='(')
			{
			
				pstfix[p]=temp;p++;
			}
		}
		else if(exp[i]=='}')
		{
		
			while((temp=chPoP())!='{')
			{
			
				pstfix[p]=temp;p++;
			}
		}
		else if(exp[i]==']')
		{
		
			while((temp=chPoP())!='[')
			{
			
				pstfix[p]=temp;p++;
			}
		}	
		else
		{
			if(precedence(exp[i])<=precedence(staCK[TOPP]))
			{
				pstfix[p]=chPoP();p++;
				chPusH(exp[i]);
			}
			else if(precedence(exp[i])>precedence(staCK[TOPP])){
				chPusH(exp[i]);
			}
		}
		
	}
	while(TOPP!=-1)
	{
		pstfix[p]=chPoP();p++;
	}

	pstfix[p] = '\0';
}


#define inffpstt 
#endif
