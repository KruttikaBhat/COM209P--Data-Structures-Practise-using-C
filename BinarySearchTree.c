#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};
struct node *root=NULL;


void insert(int x,struct node *ptr)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        //struct node *ptr=root;
        struct node *tptr=NULL;
        while(ptr!=NULL)
        {
            tptr=ptr;
            if(x<ptr->data)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }
        if(x<tptr->data)
            tptr->left=temp;
        else
            tptr->right=temp;
    }
    printf("\ninserted\n");
}

void delete(int x)
{
    struct node *ptr=root;
    struct node *tptr=NULL;
    while(ptr!=NULL)
    {
        if(ptr->data==x)
            break;
        else
        {
            tptr=ptr;
            if(x<ptr->data)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }
    }

    //if no children
    if(ptr->right==NULL&&ptr->left==NULL)
    {
        if(tptr==NULL)
            root=NULL;
        else if(x<tptr->data)
            tptr->left=NULL;
        else
            tptr->right=NULL;

    }

    //x has 2 children
    else if(ptr->right!=NULL&&ptr->left!=NULL)
    {
        struct node *succ=ptr->right;
        struct node *psucc=ptr;
        while(succ->left!=NULL)
        {
            psucc=succ;
            succ=succ->left;
        }
        ptr->data=succ->data;
        if(succ->data<psucc->data)
            psucc->left=succ->right;
        else
            psucc->right=succ->right;
    }
    //x has 1 child
    else
    {
        if(ptr->data<tptr->data)
        {
            if(ptr->right!=NULL)
                tptr->left=ptr->right;
            else
                tptr->left=ptr->left;
        }
        else
        {
            if(ptr->right!=NULL)
                tptr->right=ptr->right;
            else
                tptr->right=ptr->left;
        }
    }
}



void preorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }

}


int count=0;
void inordersort(struct node *ptr,int a[])
{
    if(ptr==root)
    {
        count=0;
    }
    if(ptr!=NULL)
    {
        inordersort(ptr->left,a);
        a[count]=ptr->data;
        count++;
        inordersort(ptr->right,a);
    }
    else
        return;

}

void inorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
    else
        return;
}

void postorder(struct node *ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ",ptr->data);
    }
    else
        return;
}

int counter(struct node *ptr)
{

    int c=1;
     if(ptr==NULL)
        return(0);
    else
    {
        c+=counter(ptr->left);
        c+=counter(ptr->right);
        return(c);
    }

}

int h(struct node *ptr)
{
    int left=0;
    int right=0;

    if(ptr==NULL)
        return(0);

    else
    {
        left=h(ptr->left);
        right=h(ptr->right);
        if(left>right)
            return(left+1);
        else
            return(right+1);

    }

}

void sort()
{
    int n,i;
    root=NULL;
    printf("\nEnter the number of numbers\n");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the numbers\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    for(i=0;i<n;i++)
    {
        insert(a[i],root);
    }
    //inorder(root);
    inordersort(root,a);
    printf("\nAfter sorting\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}



int main()
{
    int x,c;
    do{
        printf("\nEnter one of the below options:\n1.Insert\n2.Traversal\n3.Number of nodes\n4.Height of tree\n5.Delete a node\n6.Sort an array\n7.exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                printf("\nEnter the data to be inserted\n");
                scanf("%d",&x);
                insert(x,root);
                printf("\nInserted\n");
                break;
            }
        case 2:
            {
                printf("\nWhich type of traversal do you want?(preorder=1,inorder=2,postorder=3)\n");
                scanf("%d",&x);
                if(x==1)
                    preorder(root);
                else if(x==2)
                    inorder(root);
                else if(x==3)
                    postorder(root);
                else
                    printf("\nEnter a correct option\n");
                break;
            }
        case 3:
            {
                int ctr=0;
                ctr=counter(root);
                printf("\nThe number of nodes is %d\n",ctr);
                break;
            }
        case 4:
            {
                int height=h(root);
                printf("\nThe height of the tree is %d\n",height);
                break;
            }
        case 5:
            {
                inorder(root);
                printf("\nEnter the number to delete\n");
                scanf("%d",&x);
                delete(x);
                break;
            }
        case 6:
            {
                sort();
                break;

            }
        case 7:
            break;
        default:
            printf("\nEnter a correct option\n");
            break;

        }

    }while(c!=7);


return(0);
}
