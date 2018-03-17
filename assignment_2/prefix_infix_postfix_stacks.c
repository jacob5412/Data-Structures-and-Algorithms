#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

char infix[20],postfix[20];
char x;
int top=-1, s[30];
char y,c;
int MAX=30;

void push(int);
int pop();
int stop();
int priority(int);


int main()
{
	int i,j=0; 
      printf("Enter the infix expression");
       scanf("%s",infix);
        
       i=0;
       x=infix[i]; i++;
       
       while(x!='#')
       { 
           //printf("success");
	   if(isalpha(x)) { postfix[j]=x; j++;}
        
	   else if( x=='(')
                push(x);
           else if( x== ')')
           {
                 c=pop();
                while(c!='(') { postfix[j]=c; j++; c=pop(); }
           }
	   else 
	   {
                  if(priority(x) > priority(stop()) )
			push(x);
		  else
		  {
			while(priority(stop()) >= priority(x))
			{ c=pop(); postfix[j]=c; j++;}
                       push(x);
		  }
	
	   }
         x=infix[i]; i++;

       } //end while

      while(top>=0) { postfix[j]=pop(); j++; } //remaining expression from stack

      printf("Postfix expression is: %s",postfix);
return 1;
}//end main

void push(int y)
{
    if((top+1)==MAX) { printf("Stack Overflow"); exit(0); }
    else
	{
          top++;
	    s[top]=y;
        }
}

int pop()
{
   int val;
   if (top==-1) return -1;
   else 
     {  val=s[top];
        top--;
        return val;
     }
}

int stop()
{
         if(top==-1) return -1;
	 else
            return s[top];    
}	

int priority(int x)
{
   if (x=='(') return 0;
   else if ( x=='+' || x=='-') return 1;
   else if ( x=='*' || x=='/' || x=='%') return 2;
   else if (x=='^') return 3;
   else return -1;
}
