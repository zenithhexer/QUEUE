# QUEUE
This is a linear data stucture.

# Types of QUEUE:

  1. Linear QUEUE
  2. Circular QUEUE
  3. Priority QUEUE
  4. DEQUE
      -  Input restricted DEQUE
      -  Output resttricted DEQUE

All these QUEUE can be prepared using both ARRAY and LINKED LIST.

**1.1 The code for Lnear QUEUE (using ARRAY) is given below:**
```bash
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
```
**1.2. The code for Lnear QUEUE (using LINKED LIST) is given below:**
```bash
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
```
