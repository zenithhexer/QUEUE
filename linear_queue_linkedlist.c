#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

void enqueue();
void dequeue();
void display();
void peek();

int main()
{   
    printf("\t\t\tLinear QUEUE (using Linked List)\t\t\t\n");
    printf("\t\t\t********************************\t\t\t\n");

    int ch;
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
    struct node * newnode;
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter data: ");
    scanf("%d",&x);

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node * temp;
    temp = front;

    if(rear == NULL && front == NULL)
    {
        printf("\nThe QUEUE is empty.\n");
    }
    else
    {
        printf("\n%d is deleted.\n",front->data);
        front = front->next;
        free(temp);
    }
}

void display()
{
    struct node * temp;
    temp = front;

    if(rear == NULL && front == NULL)
    {
        printf("\nThe QUEUE is emmpty.\n");
    }
    else
    {   
        printf("\nThe elements in the QUEUE : ");
        while(temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void peek()
{
    if(rear == NULL && front == NULL)
    {
        printf("\nThe QUEUE is empty.\n");
    }
    else
    {
        printf("\n%d is in front\n",front->data);
    }
}