#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

struct node
{
    int data1;
    struct node *next;
};
struct node *head = NULL;
void inserting(int);
void deleting();
void display();
int details();

void main()
{
    int choice,flag;
    while (1)
    {
    printf("\n\t\t\tTicket booking management\t\t\t");
    printf("\nMENU");
    printf("\n1.Book ticket");
    printf("\n2.Cancel ticket");
    printf("\n3.check ticket");
    printf("\n4.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        flag = details();
        inserting(flag);
        break;
    case 2:
        deleting();
        break;
    case 3:
        display();
        break;
    case 4:
        exit(0);
        break;
    default:
        printf("\nEnter correct option");
    }
    }
}
int details()
{
    char name[20];
    int no,ad;
    printf("\nEnter name:");
    scanf("%s",&name);
    printf("\nEnter number:");
    scanf("%d",&no);
    printf("\nEnter adhar number:");
    scanf("%d",&ad);
    int rand_num;
    rand_num = rand()%50;
    printf("%d ", rand_num);
    printf("\nThis code is to be remembered");
    printf("\nSeat allocated");
    return rand_num;
}
void inserting(int item)
{
    struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:");
                return;
        }
        temp->data1 = item;
        temp->next =NULL;
        if(head==NULL)
        {
                head=temp;
        }
        else
        {
                temp->next=head;
                head=temp;
        }
}
void deleting()
{
    int code;
    if(head == NULL)
    {
        printf("\nNo tickets booked");
        return;
    }
    struct node *temp ;
    printf("\nEnter the code : ");
    scanf("%d",&code);
    temp = head;
    while(temp != NULL)
    {
        if(temp->data1 == code)
        {
            head = head->next;
            free(temp);
            break;
        }
    }
    printf("\nTicket cancelled...");
}
void display()
{
    int code;
    struct node *temp;
    printf("\nEnter the code:");
    scanf("%d",&code);
    if(head==NULL)
        {
                printf("\nno such ticket");
                return;
        }
    else
        {
    while(temp != NULL)
    {
        temp = head;
        if(temp->data1 == code)
        {
           printf("Your seat is booked and your code is %d",temp->data1);
        }
        else
        {
            printf("\nWrong code");
        }
    }
        }
}
