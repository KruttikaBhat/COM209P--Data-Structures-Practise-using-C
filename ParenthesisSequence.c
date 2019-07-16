#include<stdio.h>
#include<string.h>
struct stack
{
    char a[30];
    int count;
};
/*
struct stack push(struct stack *p)
{
    p->top++;
    p->c[p->top]=p->count;
    for(int i=0;i<=p->top;i++)
        printf("%d ",p->c[i]);
    return(*p);
};

struct stack pop(struct stack *p)
{
    p->top--;
    for(int i=0;i<=p->top;i++)
        printf("%d ",p->c[i]);
    return(*p);
};

*/
int main()
{
    struct stack s;
    s.count=0;
    int i,n;
    printf("\nEnter the size and sequence of parenthesis\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%c",&s.a[i]);
    }


        for(i=0;i<strlen(s.a)&&i<=strlen(s.a)-i-1;i++)
        {
            if(s.a[i]=='(')
            {
                s.count++;
                printf("\n%d",s.count);
            }
            else
            {
                s.count--;
                printf("\n%d",s.count);
                if(s.count<0)
                    break;
            }
        }

    if(s.count==0&&i==strlen(s.a))
        printf("\nThe sequence is complete\n");
    else
        printf("\nThe sequence is incomplete\n");

return(0);
}
