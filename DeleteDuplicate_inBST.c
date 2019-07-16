#include<stdio.h>
#include<stdlib.h>
//delete duplicate numbers in bst
struct node
{
    int data;
    struct node *left,*right;
};
struct node *root=NULL;

void insert(struct node *ptr,int x)
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
int a[30];

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

void search(struct node *ptr,int x)
{
    struct node *pptr=NULL;
    while(ptr!=NULL)
    {

        if(x==ptr->data)
        {
            if(ptr->right!=NULL)
            {
                if(x<pptr->data)
                {
                    pptr->left=ptr->right;
                    search(pptr->left,x);
                }
                else
                {
                    pptr->right=ptr->right;
                    search(pptr->right,x);
                }

            }
            else
            {
                ptr=NULL;
                if(x<pptr->data)
                    pptr->left=NULL;
                else
                    pptr->right=NULL;
            }


        }
        else
        {
            pptr=ptr;
            if(x<ptr->data)
                ptr=ptr->left;
            else
                ptr=ptr->right;
        }

    }
    return;
}

int temp=0;

void duplicate(struct node *ptr)
{
    if(ptr!=NULL)
    {
        temp=ptr->data;
        search(ptr->right,temp);
        duplicate(ptr->left);
        duplicate(ptr->right);
    }
    else
        return;

}

//modify the tree without making the tree linear
int main()
{
    int x;
    char c;
    printf("\nEnter the tree\n");
    do{
        scanf("%d",&x);
        insert(root,x);
        getchar();
        printf("\nEnter another element?\n");
        c=getchar();
    }while(c=='y');

    printf("\nBefore\n");
    printf("\nInorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);

    duplicate(root);

    printf("\nAfter\n");
    printf("\nInorder\n");
    inorder(root);
    printf("\nPreorder\n");
    preorder(root);
}


//Using array
int main()
{
    int i,x;
    char c;
    printf("\nEnter the tree\n");
    do{
        scanf("%d",&x);
        insert(root,x);
        getchar();
        printf("\nEnter another element?\n");
        c=getchar();
    }while(c=='y');
    inordersort(root,a);

    printf("\nThe sorted array is\n");
    for(i=0;i<count;i++)
        printf("%d ",a[i]);

    root=NULL;

    int temp=0;
    for(i=0;i<count;i++)
    {
        if(a[i]!=temp)
        {
            temp=a[i];
            insert(root,a[i]);
        }
    }
    printf("\nThe array after removal of duplicated numbers is\n");
    inorder(root);
    preorder(root);
    return(0);
}

