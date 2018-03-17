/*Program for implementing circular queue*/

#include<stdio.h>
#include<stdlib.h> 

#define max_size 10
int cqueue[max_size],front=-1,rear=-1;

void insert();
void del();
void display();
int isFull();
int isEmpty();

int main()
{
        int choice;
        do{
 
                printf("\n\n--------CIRCULAR QUEUE OPERATIONS-----------\n");
                printf("1.Enqueue\n");
                printf("2.Dequeue\n");
				printf("3.isFull\n");
				printf("4.isEmpty\n");
                printf("5.Display\n");
                printf("6.Exit\n");
                printf("-----------------------");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1: 
						insert();
						break;
                        
						case 2:
						del();
						break;
						
                        case 5:
						display();
						break;
                        
						case 6:
						exit(0);
						break;
						
						case 3:
						if((isFull())==0)
							printf("Overflown: False\n");
						else
							printf("Overflown: True\n");
						break;
						
						case 4:
						if((isEmpty())==0)
							printf("Not Empty\n");
						else
							printf("Empty\n");
						break;
										
                        default:
						printf("\nInvalid choice:\n");
						break;
                }
        }while(choice!=6);
 
}
void insert() //Inserting an element in to the queue
{
        int item;
        if(front==(rear+1)%max_size)
        {
                printf("\nQueue Overflow:");
        }
        else
        {
                printf("Enter the element to be inserted:\t");
                scanf("%d",&item);
                rear=(rear+1)%max_size;
                cqueue[rear]=item;
 
                if(front==-1)
                {
                        front=0;
                        rear=0;
                }
 
        }
 
}//end of insert()
 
void del()      //deleting an element from the queue
{
        int item;
        if(front==-1)
        {
                printf("\nQueue Underflow:");
        }
        else
        {
                item=cqueue[front];
                printf("\nThe deleted element: %d\t",item);
                if(front==rear)
                {
                        front=-1;
                        rear=-1;
                }
                else
                {
                        front=(front+1)%max_size;
                }
 
        }
}//end of del()
 
void display()  //To display the queue elements
{
        int i;
        if(front==-1)
        {
                printf("\nQueue is Empty:");
        }
        else
        {
                printf("\nThe queue elements are:\n" );
                if(front<rear)
                {
                        for(i=front;i<=rear;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                }
                else
                {
                        for(i=0;i<=rear;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                        for(i=front;i<max_size;i++)
                        {
                                printf("%d\t",cqueue[i]);
                        }
                }
 
        }
 
}//end of display()

int isEmpty() 
{
	if (front==-1) return 1;
	else
		return 0;
}/*End of isEmpty()*/

int isFull() 
{
	if((front==0 && rear==max_size-1)||(front==rear+1)) 
		return 1;
	else
		return 0;
}/*End of isFull()*/
