#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int NoOfEle=0;
struct hash *arr=NULL;

struct node
{
    int rno,marks;
    char name[50];
    struct node *next;
};

struct hash{
    struct node *head;
    int count;

};


void insert(int rno,char name[],int marks)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->rno=rno;
    newnode->marks=marks;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    int index=rno%NoOfEle;
    struct node *ptr=arr[index].head;

    if(arr[index].count==0)
    {
        arr[index].head=newnode;
        arr[index].count++;
        return;
    }
    while(ptr->next)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    arr[index].count++;
    return;
}

int search(int rno)
{
    int index=rno%NoOfEle,flag=0;
    struct node *ptr=arr[index].head;
    if(!ptr)
    {
        printf("\nElement doesn't exist\n");
        return(flag);
    }
    if(arr[index].count==0)
    {
        printf("\nElement doesn't exist\n");
        return(flag);
    }
    while(ptr)
    {
        if(ptr->rno==rno)
        {
            flag=1;
            printf("\nRoll No:%d  Name:%s   Marks:%d\n",ptr->rno,ptr->name,ptr->marks);
            return(flag);
        }
        ptr=ptr->next;
    }
    if(flag==0)
        printf("\nElement not found\n");
    return(flag);
}

void delete(int rno)
{
    int index=rno%NoOfEle,flag;
    struct node *ptr=arr[index].head;
    flag=search(rno);
    if(flag==1)
    {
        struct node *temp=ptr;
        while(ptr)
        {
            if(ptr->rno==rno)
            {
                temp->next=ptr->next;
                arr[index].count--;
                free(ptr);
            }
            temp=ptr;
            ptr=ptr->next;
        }
    }
    return;
}

void display()
{
    int i;
    struct node *ptr;
    for(i=0;i<NoOfEle;i++)
    {
        if(arr[i].count==0)
            continue;
        ptr=arr[i].head;
        printf("\nElements at index %d are\n",i);
        while(ptr)
        {
            printf("\nRoll No:%d   Name:%s   Marks:%d\n",ptr->rno,ptr->name,ptr->marks);
            ptr=ptr->next;
        }

    }
    return;
}

int main()
{
    int n,c,rollno,x;
    char name[50];
    printf("\nEnter the no of elements\n");
    scanf("%d",&n);
    NoOfEle=n;
    arr=(struct hash*)calloc(n,sizeof(struct hash));
    while(c!=5)
    {
        printf("\nEnter one of the below options\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter the roll no\n");
            scanf("%d",&rollno);
            printf("\nEnter the name\n");
            getchar();
            fgets(name,50,stdin);
            printf("\nEnter the marks\n");
            scanf("%d",&x);
            insert(rollno,name,x);
            break;
        case 2:
            printf("\nEnter the roll no of element to be deleted\n");
            scanf("%d",&x);
            delete(x);
            break;
        case 3:
            printf("\nEnter the roll no of element to be searched\n");
            scanf("%d",&x);
            search(x);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nEnter a correct option\n");
            break;

        }
    }

    return(0);
}
















































/*
struct hash *array=NULL;
int NumOfEle=0;

struct node
{
    struct node *next;
    int rollno;
    char name[100];
    int marks;
};

struct hash
{
    struct node *head;
    int count;
};

struct node *NewNode(int rollno,char name[],int marks)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->rollno=rollno;
    newnode->marks=marks;
    strcpy(newnode->name,name);
    newnode->next=NULL;
    return(newnode);
};

void insert(int rollno,char name[],int marks)
{
    struct node *newnode=NewNode(rollno,name,marks);
    int hashindex=rollno%NumOfEle;
    struct node *newhead=array[hashindex].head;
    if(!array[hashindex].head)
    {
        array[hashindex].head=newnode;
        array[hashindex].count=1;
        return;
    }
    newnode->next=array[hashindex].head;
    array[hashindex].head=newnode;
    array[hashindex].count++;
    return;

}

void delete(int key)
{
     int hashindex=key%NumOfEle,flag=0;
     struct node *ptr,*temp;
     ptr=temp=array[hashindex].head;
     if(!ptr)
     {
         printf("The element is not present");
         return;
     }

     while(ptr)
     {
         if(ptr->rollno==key)
         {
             flag=1;
             if(ptr==array[hashindex].head)
                array[hashindex].head=ptr->next;
             else
                temp->next=ptr->next;

             array[hashindex].count--;
             free(ptr);
             break;
         }
         temp=ptr;
         ptr=ptr->next;

     }
     if(flag==1)
        printf("\nElement has been deleted\n");
     else
        printf("\nElement not present in list\n");
}


void search(int key)
{
    int hashindex=key%NumOfEle,flag=0;
    struct node *ptr=array[hashindex].head;
    if(!ptr)
    {
        printf("\nElement not present\n");
        return;
    }
    if(array[hashindex].count==0)
    {
        printf("\nElement not present\n");
        return;
    }
    while(ptr)
    {
        if(ptr->rollno==key)
        {
            flag=1;
            printf("\nRoll no: %d\nName: %s \nMarks: %d\n",ptr->rollno,ptr->name,ptr->marks);
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0)
        printf("\nElement not present\n");
    return;
}


void display()
{
    struct node *ptr;
    int i;
    for(i=0;i<NumOfEle;i++)
    {
        if(array[i].count==0)
            continue;
        ptr=array[i].head;
        if(!ptr)
            continue;
        printf("\nData at index %d:\n",i);
        while(ptr)
        {
            printf("\nRoll no: %d  Name: %s  Marks: %d \n",ptr->rollno,ptr->name,ptr->marks);
            ptr=ptr->next;
        }

    }
    return;
}


int main()
{
    int c,rollno,x;
    char name[100];
    printf("\nEnter the number of elements\n");
    scanf("%d",&NumOfEle);
    array=(struct hash*)calloc(NumOfEle,sizeof(struct hash));

    while(c!=5)
    {
        printf("\nEnter one of the below options\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter the roll number\n");
            scanf("%d",&rollno);
            printf("\nEnter the name\n");
            getchar();
            fgets(name,100,stdin);
            printf("\nEnter the marks\n");
            scanf("%d",&x);
            insert(rollno,name,x);
            break;
        case 2:
            printf("\nEnter the roll no of element to be deleted\n");
            scanf("%d",&x);
            delete(x);
            break;
        case 3:
            printf("\nEnter the roll no of element to be searched\n");
            scanf("%d",&x);
            search(x);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nEnter a correct option\n");
            break;

        }
    }
    return(0);
}
*/
