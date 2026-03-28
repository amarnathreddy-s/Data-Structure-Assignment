#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;   
};
struct Node *front=NULL;
struct Node *rear=NULL;
void enqueue(int x)
{
    struct Node *newnode;
    newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL)
    {
        printf("allocation is failed");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    if(rear==NULL)
    {
        rear=front=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}
void dequeue(){
    if(front==NULL){
        printf("Queue is empty");
        exit(1);
    }
    else{
        struct Node *temp;
        temp=front;
        front=front->next;
        free(temp);
    }
    if(front==NULL){
        rear=NULL;
    }
}
void peek(){
    if(front==NULL){
        printf("Queue is empty and no peek value");
        exit(1);
    }
    else{
        printf("%d is peek value\n",front->data);
    }
}
void isEmpty()
{
    if(front==NULL) printf("Queue is empty");
    else{
        printf("queue is not empty");
    }
}
void print()
{
    if(front==NULL){
        printf("Queue is empty no value to print");
        exit(1);
    }
    struct Node *temp=front;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    int cont=1;
    while(cont){
    printf("QUEUE FUNCTIONS:\n");
    printf("1: enqueue\n");
    printf("2: dequeue\n");
    printf("3: peek\n");
    printf("4: print\n");
    printf("5: exit\n");
    printf("Enter choice: \n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("enter data: \n");
        int data;
        scanf("%d",&data);
        enqueue(data);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        peek();
        break;

        case 4:
        print();
        break;

        default:
        exit(1);
    }
    printf("Do you want to continue? ");
    scanf("%d",&cont);
    }
}
