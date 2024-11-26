#include<stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue();
void dequeue();
void display();
void peek();

int main()
{   
    printf("\t\t\tLinear QUEUE (using array)\t\t\t\n");
    printf("\t\t\t**************************\t\t\t");

    char ch;
    do
    {
        printf("\nEnter 1. to INSERT.\n");
        printf("Enter 2. to DELETE.\n");
        printf("Enter 3. to DISPLAY.\n");
        printf("Enter 4. to PEEK.\n");
        printf("Enter 0. to EXIT.\n");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch (ch)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            
            default:
                break;
        }

    } while (ch != 0);
    

    return 0;
}

void enqueue()
{
    int x;
    printf("\nEnter data: ");
    scanf("%d",&x);

    if(rear == N-1)
    {
        printf("\nOverflow..\n");
    }
    else if(rear == -1 && front == -1)
    {
        rear = front = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQUEUE is empty..\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        printf("\n%d is deleted.\n",queue[front]);
        front++;
    }
    
}

void display()
{
    if(rear == -1 && front == -1)
    {
        printf("\nQUEUE is empty.\n");
    }
    else
    {   
        printf("\nThe elements in QUEUE: ");
        for (int i = front; i< rear+1;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if(rear == -1 && front == -1)
    {
        printf("\nQUEUE is empty\n");
    }
    else
    {
        printf("\nThe front element is : %d\n",queue[front]);
    }
}