#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *np,*pp;
};
struct node *list1,*list2;

void create(struct node *t)
{
    int i,x;
    struct node *th=t,*thptr;
    printf("\nEnter the number of elements\n");
    scanf("%d",&x);
    printf("\nEnter the numbers\n");
    for(i=0;i<x;i++);
    {
        scanf("%d",t->data);
        thptr=th;

        if(i<x-1&&i!=0)
        {
            while(thptr->np!=NULL)
            {
                thptr=thptr->np;
            }
            t->pp=thptr;
            thptr->np=t;
        }
        else if(i==x-1)
        {
            while(thptr->np!=NULL)
            {
                thptr=thptr->np;
            }
            t->pp=thptr;
            t->np=th;
            thptr->np=t;
            th->pp=t;
        }
        if(i<x-1)
        {
            t->np=(struct node*)malloc(sizeof(struct node));
            t=t->np;
            t->np=NULL;
        }
    }
    thptr=th;
    i=0;
    printf("\nThe entered list is\n");
    while(i<x)
    {
        printf("%d ",thptr->data);
        thptr=thptr->np;
        i++;
    }

}

void concatenate(struct node *l1,struct node *l2)
{
    struct node *thptr=l1;
    while(thptr->np!=l1)
    {
        thptr=thptr->np;
    }
    thptr->np=l2;
    (l2->pp)->np=l1;
    l2->pp=thptr;
    l1->pp=l2;
    thptr=l1;
    while(thptr->np!=l1)
    {
        printf("%d ",thptr->data);
        thptr=thptr->np;
    }
    printf("%d ",thptr->data);
}

int main()
{

    struct node *list1=(struct node*)malloc(sizeof(struct node));
    struct node *list2=(struct node*)malloc(sizeof(struct node));
    list1->np=NULL;
    list1->pp=NULL;
    list2->np=NULL;
    list2->pp=NULL;
    list1->data=0;
    list2->data=0;
    printf("\nEnter the first list\n");
    create(list1);
    printf("\nEnter the second list\n");
    create(list2);
    concatenate(list1,list2);
    return(0);
}
