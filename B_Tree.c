#include<stdio.h>
#include<stdlib.h>

int count=0;

struct node
{
    int key1;
    int key2;
    int key3;
    struct node *child1;
    struct node *child2;
    struct node *child3;
    struct node *parent;
    int count;
    int type;             //1->parent 2->bucket
};

struct node *head=NULL;

void sort(struct node *ptr)
{
    int temp;
    if(ptr->key1>ptr->key2)
    {
        temp=ptr->key1;
        ptr->key1=ptr->key2;
        ptr->key2=temp;
    }
    if(ptr->key1>ptr->key3)
    {
        temp=ptr->key1;
        ptr->key1=ptr->key3;
        ptr->key3=temp;
    }
    if(ptr->key2>ptr->key3)
    {
        temp=ptr->key2;
        ptr->key2=ptr->key3;
        ptr->key3=temp;
    }
}

void arrsort(int a[],int n)
{
    int i,temp,j;
    for(i=1;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j]<a[j-1])
            {
                temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }

        }
    }
}


struct node * splitbucket(struct node *ptr,struct node *sib,int x)
{
	sib=(struct node *)malloc(sizeof(struct node));
    int a[4];
    a[0]=ptr->key1;
    a[1]=ptr->key2;
    a[2]=ptr->key3;
    a[3]=x;
    arrsort(a,4);
    ptr->key1=a[0];
    ptr->key2=a[1];
    ptr->key3=1111;
    ptr->count=2;
    sib->key1=a[2];
    sib->key2=a[3];
    sib->key3=1111;
    sib->count=2;
    sib->child1=NULL;
    sib->child2=NULL;
    sib->child3=NULL;
    ptr->child1=NULL;
    ptr->child2=NULL;
    ptr->child3=NULL;
    ptr->type=2;
    sib->type=2;
    sib->parent=NULL;
    return(sib);

}


struct node * splitparent(struct node *pptr,struct node *ptr,struct node *newpptr,struct node *new)
{
	newpptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==pptr->child1)
    {
        newpptr->child1=pptr->child2;
        newpptr->child1->parent=newpptr;

		newpptr->child2=pptr->child3;
        newpptr->child2->parent=newpptr;

		pptr->child2=new;
        new->parent=pptr;
        ptr->parent=pptr;

    }
    else if(ptr==pptr->child2)
    {
        newpptr->child1=new;
        new->parent=newpptr;

		newpptr->child2=pptr->child3;
        newpptr->child2->parent=newpptr;

    }
    else if(ptr==pptr->child3)
    {
        newpptr->child1=ptr;
        ptr->parent=newpptr;

        newpptr->child2=new;
        new->parent=newpptr;
    }
    pptr->child3=NULL;
    newpptr->child3=NULL;
    pptr->count=2;
    newpptr->count=2;
    pptr->type=1;
    newpptr->type=1;
    newpptr->parent=NULL;

    struct node *temp=pptr->child2;
    while(temp->type!=2)             //traverse to get the key since child of parent may not be a bucket
        temp=temp->child1;
    pptr->key1=temp->key1;

    temp=newpptr->child2;
    while(temp->type!=2)
        temp=temp->child1;
    newpptr->key1=temp->key1;
    pptr->key2=0;
    pptr->key3=0;
    newpptr->key2=0;
    newpptr->key3=0;
    return(newpptr);
}


void insert(struct node *ptr,int x)
{
    int i;
    if(count==0)  //empty b tree
    {
        count++;
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->key1=x;
        ptr->key2=1111;             //1111->empty
        ptr->key3=1111;
        ptr->child1=NULL;
        ptr->child2=NULL;
        ptr->child3=NULL;
        ptr->count=1;
        ptr->type=2;
        ptr->parent=NULL;
        head=ptr;
        printf("\ninsertion done count:%d\n",count);
        return;
    }
    if(count<3)   //first 3 insertions
    {
        count++;
        if(count==2)
            ptr->key2=x;
        if(count==3)
            ptr->key3=x;
        ptr->count++;
        sort(ptr);
        printf("\ninsertion done count:%d\n",count);
        return;
    }

    if(count==3)   //4th insertion
    {
        count++;
        ptr->count=4;
        struct node *sib=(struct node *)malloc(sizeof(struct node));
        sib=splitbucket(ptr,sib,x);           //sort the 4 elements

        struct node *parent=(struct node *)malloc(sizeof(struct node));

        parent->child1=ptr;       //make the parent point to the buckets
        parent->child2=sib;
        parent->child3=NULL;
        parent->key1=(parent->child2)->key1;
        parent->parent=NULL;
        parent->count=2;
        parent->type=1;
        head=parent;
        ptr->parent=head;       //make the buckets point to the parent
        sib->parent=head;
        printf("\ninsertion done count:%d\n",count);
        return;
    }
    count++;
    while(ptr->type!=2)           //traverse till we reach a bucket
    {

        if(ptr->count==2)          //when parent has only 2 children
        {
            if(x<ptr->key1)
                ptr=ptr->child1;
            else
                ptr=ptr->child2;

        }

        else if(ptr->count==3)        //when parent has 3 children
        {
            if(x<ptr->key1)
                ptr=ptr->child1;
            else if(x>ptr->key1&&x<ptr->key2)
                ptr=ptr->child2;
            else
                ptr=ptr->child3;

        }
    }

    if(ptr->count==2)
    {
        ptr->key3=x;
        sort(ptr);       //sort the bucket
        ptr->count++;
        printf("\ninsertion done count:%d\n",count);
        return;
    }

    if(ptr->count==3)    //if the bucket is already full
    {

        ptr->count=4;
        struct node *new;
        new=splitbucket(ptr,new,x);    //split the bucket and store the last 2 values in new after sorting
        struct node *pptr=ptr->parent;
        while(pptr)
        {

            if(pptr->count==2)    //if the parent only has 2 children
            {

                if(ptr==pptr->child1)      //when new bucket will become middle child of parent
                {
                    pptr->child3=pptr->child2;
                    pptr->child2=new;
                }
                else if(ptr==pptr->child2)    //when new bucket becomes the third child of bucket
                {
                    pptr->child3=new;
                }

                struct node *temp=pptr->child2;
                while(temp->type!=2)
                    temp=temp->child1;
                pptr->key1=temp->key1;     //bring in concept of type to traverse to get the key value;
                temp=pptr->child3;
                while(temp->type!=2)
                    temp=temp->child1;
                pptr->key2=temp->key1;
                new->parent=pptr;
                ptr->parent=pptr;
                //printf("inside if ptr parent %d %d",ptr->parent->key1,new->parent->key1);
                pptr->count=3;       //increment count
                printf("\ninsertion done count:%d\n",count);
                return;

            }

            else if(pptr->count==3)      //if the parent already has 3 children
            {

                struct node *newpptr;
                newpptr=splitparent(pptr,ptr,newpptr,new);
                //printf("ptr parent key:%d new parent key:%d",ptr->parent->key1,new->parent->key1);
                ptr=pptr;
                new=newpptr;
                pptr=ptr->parent;                             //make ptr point to its parent
                if(pptr==NULL)                   //check whether there is already some parent existing to attach the new parent
                {
                    struct node *newhead=(struct node *)malloc(sizeof(struct node));

                    newhead->child1=ptr;
                    newhead->child2=new;
                    newhead->child3=NULL;
                    ptr->parent=newhead;
                    new->parent=newhead;
                    new->type=1;
                    new->count=2;

                    struct node *temp=newhead->child2;     //get the key value
                    while(temp->type!=2)
                    {
                        temp=temp->child1;
                    }

                    newhead->key1=temp->key1;
                    newhead->key2=0;
                    newhead->key3=0;
                    newhead->parent=NULL;
                    newhead->count=2;
                    newhead->type=1;
                    //printf("inside else if '3' count parent key %d %d",ptr->parent->key1,new->parent->key1);
                    head=newhead;
                    printf("\ninsertion done count:%d\n",count);
                    return;
                }

            }


        }//while ends

    printf("\nend");
    }//if case ends
    printf("\ninsertion done\n");
    return;
}





void display(struct node *ptr)
{
    if(ptr)
    {
        display(ptr->child1);
        display(ptr->child2);
        display(ptr->child3);
        if(ptr->type==1)
            printf("\nParent values:  %d  %d\n",ptr->key1,ptr->key2);
        if(ptr->type==2)
            printf("\nBucket values:  %d  %d  %d\n",ptr->key1,ptr->key2,ptr->key3);
    }
    else
        return;
}

int main()
{
    int c,i,x;

    while(c<3)
    {
        printf("\nEnter one of the below options\n1.Insert\n2.Display\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter the number to be inserted\n");
            scanf("%d",&x);
            insert(head,x);
            break;
        case 2:
            display(head);
            break;
        default:
            printf("\nEnter correct option\n");
            break;
        }

    }

    return(0);
}
