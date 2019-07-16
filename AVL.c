#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left,*right;
};

int h(struct node *ptr)
{
    if(ptr==NULL)
        return(-1);
    else
       return(ptr->height);
}

int UpdateHeight(struct node *ptr)
{
    int hl=h(ptr->left),hr=h(ptr->right);
    if(hl<hr)
        return(1+hr);
    else
        return(1+hl);
}

int GetBalance(struct node *ptr)
{
    if(ptr==NULL)
        return(0);
    else
        return(h(ptr->left)-h(ptr->right));
}

struct node *RotateRight(struct node *Aff)
{
    struct node *ChildOfAff=Aff->left;

    Aff->left=ChildOfAff->right;
    ChildOfAff->right=Aff;

    Aff->height=UpdateHeight(Aff);
    ChildOfAff->height=UpdateHeight(ChildOfAff);

    return(ChildOfAff);

};

struct node *RotateLeft(struct node *Aff)
{
    struct node *ChildOfAff=Aff->right;

    Aff->right=ChildOfAff->left;
    ChildOfAff->left=Aff;

    Aff->height=UpdateHeight(Aff);
    ChildOfAff->height=UpdateHeight(ChildOfAff);

    return(ChildOfAff);

};




struct node *insert(struct node *ptr,int x)
{

    if(ptr==NULL)
    {
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
        ptr->height=0;
        ptr->left=ptr->right=NULL;
        return(ptr);
    }

    if(x<ptr->data)
        ptr->left=insert(ptr->left,x);

    else if(x>ptr->data)
        ptr->right=insert(ptr->right,x);

    else
        return(ptr);
    ptr->height=UpdateHeight(ptr);

    int balance=GetBalance(ptr);

    if(balance>1)
    {
        if(x<ptr->left->data)
            return(RotateRight(ptr));
        else
        {
            ptr->left=RotateLeft(ptr->left);
            return(RotateRight(ptr));
        }
    }


    else if(balance<-1)
    {
        if(x>ptr->right->data)
            return(RotateLeft(ptr));
        else
        {
            ptr->right=RotateRight(ptr->right);
            return(RotateLeft(ptr));
        }
    }



    return(ptr);
};


void inorder(struct node *ptr)
{
    if(ptr)
    {
        inorder(ptr->left);
        printf("%d ",ptr->data);
        inorder(ptr->right);
    }
};

void preorder(struct node *ptr)
{
    if(ptr)
    {
        printf("%d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
};



struct node *delete(struct node *ptr,int x)
{
    if(ptr==NULL)
        return(ptr);

    if(x<ptr->data)
        ptr->left=delete(ptr->left,x);
    else if(x>ptr->data)
        ptr->right=delete(ptr->right,x);
    else
    {
        if(ptr->right==NULL||ptr->left==NULL)
        {
            struct node *temp=ptr->left?ptr->left:ptr->right;
            if(temp==NULL)
            {

                temp=ptr;
                ptr=NULL;
            }
            else
                *ptr=*temp;
            free(temp);
        }
        else
        {
            struct node *temp=ptr->right;
            while(temp->left)
                temp=temp->left;
            ptr->data=temp->data;
            ptr->right=delete(ptr->right,temp->data);
        }
    }

    if(ptr==NULL)
        return ptr;
    ptr->height=UpdateHeight(ptr);
    int balance=GetBalance(ptr);
    if(balance>1)
    {
        if(GetBalance(ptr->left)>=0)
            return RotateRight(ptr);
        else
        {
         ptr->left=RotateLeft(ptr->left);
         return RotateRight(ptr);
        }
    }

    else if(balance<-1)
    {
        if(GetBalance(ptr->right)<=0)
            return RotateLeft(ptr);
        else
        {
            ptr->right=RotateRight(ptr->right);
            return RotateLeft(ptr);
        }

    }
    return(ptr);
};

int main()
{
    struct node *root=NULL;
    int x,c;
    do{
        printf("\nEnter one of the below options\n1.Insert\n2.Delete\n3.Height of the tree\n4.Exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter the number to be inserted\n");
            scanf("%d",&x);
            root=insert(root,x);
            printf("\nAfter insertion:Inorder\n");
            inorder(root);
            printf("\nPreorder\n");
            preorder(root);
            break;
        case 2:
            printf("\nEnter the number to be deleted\n");
            scanf("%d",&x);
            root=delete(root,x);
            printf("\nAfter insertion:Inorder\n");
            inorder(root);
            printf("\nPreorder\n");
            preorder(root);
            break;
        case 3:
            printf("\n%d\n",h(root));
            break;
        case 4:
            break;
        default:
            printf("\nWrong option\n");
            break;
        }

    }while(c!=4);

}
