#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<malloc.h>

struct node
{
    int coe,pow;
    struct node *next;
};

struct node *p1=NULL,*p2=NULL,*added=NULL,*mult=NULL;
int size1=0,size2=0;

void create(struct node *temp,int x)
{
    char c;
    do{
        if(x==1)
            size1++;
        else if(x==2)
            size2++;
        printf("\nEnter the coefficient\n");
        scanf("%d",&temp->coe);
        printf("\nEnter the power\n");
        scanf("%d",&temp->pow);
        printf("\nEnter another component?\n");
        temp->next=NULL;
        getchar();
        c=getchar();
        if(c=='y')
        {
            temp->next=(struct node *)malloc(sizeof(struct node));
            temp=temp->next;
            temp->next=NULL;
        }

    }while(c=='y');
    printf("\n%c\n",c);
    return;
};

void print(struct node *temp)
{
    while(temp)
    {
        printf("%dx^%d",temp->coe,temp->pow);
        temp=temp->next;
        if(temp)
            printf(" + ");
    }
}

void add(struct node *t1,struct node *t2,struct node *t)
{

    while(t1&&t2)
    {
        if(t1->pow<t2->pow)
        {
            t->pow=t1->pow;
            t->coe=t1->coe;
            t->next=NULL;
            t1=t1->next;
        }
        else if(t2->pow<t1->pow)
        {
            t->pow=t2->pow;
            t->coe=t2->coe;
            t->next=NULL;
            t2=t2->next;
        }
        else
        {
            t->pow=t1->pow;
            t->coe=t1->coe+t2->coe;
            t->next=NULL;
            t1=t1->next;
            t2=t2->next;
        }
            if(t1||t2)
            {
                t->next=(struct node*)malloc(sizeof(struct node));
                t=t->next;
                t->next=NULL;
            }
    }
    while(t1||t2)
    {
        if(t1)
        {
            t->pow=t1->pow;
            t->coe=t1->coe;
            t->next=NULL;
            t1=t1->next;
        }
        if(t2)
        {
            t->pow=t2->pow;
            t->coe=t2->coe;
            t->next=NULL;
            t2=t2->next;
        }
        if(t1||t2)
        {
            t->next=(struct node*)malloc(sizeof(struct node));
            t=t->next;
            t->next=NULL;
        }
    }

}

void reverse(struct node *t)
{
    struct node *pre=NULL,*cur=t,*nptr;
    while(cur)
    {
        nptr=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nptr;
    }
    t=pre;
}

void multiply(struct node *m1,struct node *m2,struct node *m)
{
    struct node *thptr1,*thptr2,*mhptr;
    thptr1=m1;
    thptr2=m2;
    mhptr=m;
    int n1=size1,n2=size2,x=0;
    while(size2>0)
    {
        thptr2=m2;
        int i=1;
        while(i<n1-x)
        {
            thptr2=thptr2->next;
            i++;
        }
        while(thptr1&&thptr2)
        {
            m->coe=thptr1->coe*thptr2->coe;
            m->pow=thptr1->pow+thptr2->pow;
            thptr1=thptr1->next;
            thptr2=thptr2->next;
            if(thptr1&&thptr2)
            {
                m->next=(struct node *)malloc(sizeof(struct node));
                m=m->next;
                m->next=NULL;
                m->coe=0;
                m->pow=0;
            }
        }
        x++;
        size2--;

    }
    x=0;
    while(size1-1>0)
    {

        thptr1=m1;
        int i=1;
        while(i<n1-x)
        {
            thptr1=thptr1->next;
            i++;
        }
        while(thptr1&&thptr2)
        {
            m->coe=thptr1->coe*thptr2->coe;
            m->pow=thptr1->pow+thptr2->pow;
            thptr1=thptr1->next;
            thptr2=thptr2->next;
            if(thptr1&&thptr2)
            {
                m->next=(struct node *)malloc(sizeof(struct node));
                m=m->next;
                m->next=NULL;
                m->coe=0;
                m->pow=0;
            }
        }
        x++;
        size1--;

    }

}

int main()
{
    int x,s;
    p1=(struct node*)malloc(sizeof(struct node));
    p2=(struct node*)malloc(sizeof(struct node));
    added=(struct node*)malloc(sizeof(struct node));
    mult=(struct node*)malloc(sizeof(struct node));
    added->next=NULL;
    mult->next=NULL;
    added->coe=0;
    added->pow=0;
    mult->coe=0;
    mult->pow=0;
    do{
        printf("\nEnter one of the below options:\n1.Create\n2.Print\n3.Add 2 Polynomials\n4.Multiply 2 polynomials\n5.Exit\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
            {
                printf("\nEnter which polynomial is to be created(1 or 2)\n");
                scanf("%d",&x);
                if(x==1)
                    create(p1,1);
                else if(x==2)
                    create(p2,2);
                else
                    printf("\nWrong option\n");
                break;
            }
            case 2:
            {
                printf("\nEnter which polynomial is to be printed(1 or 2)\n");
                scanf("%d",&x);
                if(x==1)
                    print(p1);
                else if(x==2)
                    print(p2);
                else
                    printf("\nWrong option\n");
                break;
            }
            case 3:
            {
                add(p1,p2,added);
                printf("\nThe polynomial after adding is:\n");
                print(added);
                break;
            }
            case 4:
            {
                reverse(p2);
                multiply(p1,p2,mult);
                printf("\nThe polynomial after multiplying is:\n");
                print(mult);
                break;
            }
            case 5:
                break;
            default:
                printf("\nEnter a correct option\n");
                break;
        }

    }while(s!=5);

    return(0);
}
