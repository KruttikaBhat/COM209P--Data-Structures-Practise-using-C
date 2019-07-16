#include<stdio.h>

struct stack
{
    int top;
    int a[5];

};

struct stack push(struct stack *p)
{
    int x;
    if(p->top<4)
    {
        printf("\nEnter an integer\n");
        scanf("%d",&x);
        p->top++;
        p->a[p->top]=x;
        printf("\nThe stack after pushing the integer is:\n");
       for(int i=0;i<=p->top;i++)
       {
          printf("%d ",p->a[i]);
       }

    }
    else
    {
        printf("\nThe stack is full!!!\n");
    }
    return(*p);

}

struct stack pop(struct stack *p)
{
   if((p->top)>-1)
   {
       printf("%d has been removed",p->a[p->top]);
       p->top--;
       printf("\nThe stack after popping is:\n");
       for(int i=0;i<=p->top;i++)
       {
          printf("%d ",p->a[i]);
       }
   }
   else if(p->top==-1)
    printf("\nThe stack is empty!\n");
   return(*p);

}
/*
void display(int a[n],int top)
{
    if(top!=-1)
    {
        for(int i=0;i<=top;i++)
        {
            if(i==top)
                printf("%d\n",a[top]);
            printf("%d<-",a[i]);
        }

    }
    else
        printf("\nStack is empty");

}
*/

int main()
{
   struct stack s;
   int c;
   s.top=-1;
    do{
        printf("\nEnter one of the below options:\n1.push an integer\n2.pop an integer\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                {
                    push(&s);
                    break;
                }

            case 2:
                {
                    pop(&s);
                    break;
                }

            default:
                {
                    printf("Enter a correct option number\n");
                    break;
                }

        }

    }while(c>0);



return(0);
}

