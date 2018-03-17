/* Program for creating a stack using an array*/
#include<stdio.h> 
#include<stdlib.h>
int max=10,top=-1,s[10],choice;
void push() {
    int a;
    printf("Enter the element: ");
    scanf("%d",&a);
    if((top+1)==max)
    {
        printf("Stack overflow");
        return;
    }
    else
    {
		top++;
		s[top]=a;
		return;
    }
}
void pop() {
    if(top==-1)
    {
        printf("Stack is empty");
        return;
    }
    else;
    {
        printf("Popped element is %d",s[top]);
        top--;
    }
}
void peep() {
    int b;
    printf("Enter the position of the element you want to see from top");
    scanf("%d", &b);
    if(b>(top+1)||b<0)
    {
        printf("No element present at this position");
        return;
    }
    else
    {
        printf("Element is %d",s[top-b+1]);
        return;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
        return;
    }
    printf("->");
    for(i=top; i>0; i--) printf("%d",s[i]);
}
int main() {
    while(1) {
        printf("\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}