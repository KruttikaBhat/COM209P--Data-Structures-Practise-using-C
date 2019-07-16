#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coe;
    struct node *next;
};
int size1=0,size2=0;
struct node *poly1,*poly2,*add,*mult;

struct node * create(struct node *ptr,int x)
{
    int i,data;
    struct node *head=ptr;
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    struct node *ptr1;
    for(i=0;i<=x;i++)
    {
        printf("\nEnter the coefficient for x^%d\n",i);
        scanf("%d",&data);
        if(head==NULL)
        {
            temp->coe=data;
            head=temp;
            ptr1=head;
        }
        else
        {

            struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->next=NULL;
            temp->coe=data;
            ptr1->next=temp;
            ptr1=temp;
        }
    }

    ptr1=head;
    for(i=0;i<=x&&ptr1;i++)
    {
        printf("%dx^%d",ptr1->coe,i);
        if(ptr1->next)
            printf(" + ");
        ptr1=ptr1->next;
    }
    return(head);

}

void display(struct node *ptr)
{
    int count=0;
    while(ptr)
    {
        printf("%dx^%d",ptr->coe,count);
        if(ptr->next)
            printf(" + ");
        count++;
        ptr=ptr->next;
    }
}

void added(struct node *p1,struct node *p2,struct node *ptr)
{
    int x;
    add=ptr;
    while(p1&&p2)
    {

        x=p1->coe+p2->coe;
        p1=p1->next;
        p2=p2->next;
        if(ptr==NULL)
        {
            struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->coe=x;
            temp->next=NULL;
            ptr=temp;
        }
        else
        {
            struct node *temp=(struct node *)malloc(sizeof(struct node));
            temp->coe=x;
            temp->next=NULL;
            ptr->next=temp;
            ptr=temp;

        }
        printf("\nhi");

    }
    while(p1)
    {
        x=p1->coe;
        p1=p1->next;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coe=x;
        temp->next=NULL;
        ptr->next=temp;
        ptr=temp;
        printf("\nHI");
    }
    while(p2)
    {
        x=p2->coe;
        p2=p2->next;
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coe=x;
        temp->next=NULL;
        ptr->next=temp;
        ptr=temp;
        printf("\nHi");
    }
    printf("\nwhile done");
    ptr=add;
    int count=0;
    while(ptr)
    {
        printf("%dx^%d",ptr->coe,count);
        if(ptr->next)
            printf(" + ");
        ptr=ptr->next;
        count++;
    }
}

struct node * reverse(struct node *ptr)
{
    struct node *cur=ptr;
    struct node *pre=NULL;
    struct node *next;
    while(cur)
    {
        next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    ptr=pre;
    return(ptr);

}

void multiply(struct node *p1,struct node *p2,struct node *head)
{
    int i,j,x;
    struct node *head1=p1,*head2=reverse(p2);
    struct node *ptr=head;
    for(i=0;i<size2;i++)
    {
        p1=head1;
        p2=head2;
        ptr=head;
        x=0;
        for(j=0;j<size2-i;j++)
        {
            p2=p2->next;
        }
        while(p1&&p2)
        {
            x+=p2->coe*p1->coe;
            p1=p1->next;
            p2=p2->next;
        }
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coe=x;
        temp->next=NULL;
        if(mult==NULL)
        {
            mult=temp;
        }
        else
        {
            while(ptr->next)
                ptr=ptr->next;
            ptr->next=temp;
        }
        printf("\n1.....%d inserted\n",x);

    }
    for(i=0;i<size1;i++)
    {
        p1=head1;
        p2=head2;
        ptr=head;
        x=0;
        for(j=0;j<=i;j++)
            p1=p1->next;
        while(p1&&p2)
        {
            x+=p2->coe*p1->coe;
            p1=p1->next;
            p2=p2->next;
        }
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->coe=x;
        temp->next=NULL;
        while(ptr->next)
            ptr=ptr->next;
        ptr->next=temp;
        printf("\n.....%d inserted\n",x);

    }

    ptr=mult;
    x=0;
    while(ptr)
    {
        printf("%dx^%d",ptr->coe,x);
        if(ptr->next)
            printf(" + ");
        ptr=ptr->next;
        x++;
    }
}

int main()
{
    int x,c,n;
    do{
        printf("\nEnter an option\n1.Create\n2.Display\n3.Add\n4.Multiply\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nWhich polynomial do you want to create?\n");
            scanf("%d",&x);
            printf("\nEnter the degree\n");
            scanf("%d",&n);
            if(x==1)
                poly1=create(poly1,n);
            else
                poly2=create(poly2,n);
            break;
        case 2:
            printf("\nWhich polynomial do you want to display?");
            scanf("%d",&x);
            if(x==1)
            display(poly1);
            else if(x==2)
                display(poly2);
                else if(x==3)
                    display(add);
                    else
                    display(mult);
            break;
        case 3:
            added(poly1,poly2,add);
            break;
        case 4:
            multiply(poly1,poly2,mult);
            break;

        }
    }while(c!=5);

}
