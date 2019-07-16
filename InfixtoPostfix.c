#include<stdio.h>
#include<string.h>
#define size 10
struct stack
{
    char a[size];
    int top;
};

void push(struct stack *p,char c)
{
    p->top++;
    p->a[p->top]=c;

    printf("\nAfter pushing:\n");
    for(int i=0;i<=p->top;i++)
        printf("%c ",p->a[i]);

}

char pop(struct stack *p)
{
    char x;
    x=p->a[p->top];
    printf("\nPopped value: %c\n",x);
    p->top--;

    printf("\nAfter popping:\n");
    for(int i=0;i<=p->top;i++)
        printf("%c ",p->a[i]);
    printf("\nAfter popping top value is %d\n",p->top);

    return(x);
}

int main()
{
    struct stack s;
    s.top=-1;
    printf("\nEnter the infix expression\n\n");
    char c[20],x,temp,d[20];
    int flag=0,count=-1;
    scanf("%s",&c);
    for(int i=0;i<strlen(c);i++)
    {
        if((48<=c[i])&&(c[i]<=57))
        {
            count++;
            d[count]=c[i];
        }
        else
        {
            switch(c[i])
            {
                case'(':
                {
                    push(&s,c[i]);
                    break;
                }
                case'*':
                {
                    if(s.top==-1)
                        push(&s,c[i]);
                    else
                    while(s.top>=0)
                    {
                        if(s.a[s.top]=='/')
                        {
                            x=pop(&s);
                            count++;
                            d[count]=x;
                        }
                        else if(s.a[s.top]=='*')
                        {
                            x=pop(&s);
                            count++;
                            d[count]=x;
                        }
                        else
                        {
                             push(&s,c[i]);
                             break;
                        }

                     }

                    break;
                }
                case'/':
                {
                    push(&s,c[i]);
                    break;
                }
                case'+':
                {
                    while(s.top>=0)
                    {
                        if(s.a[s.top]=='(')
                        {
                            break;
                        }

                        else
                        {
                            x=pop(&s);
                            count++;
                            d[count]=x;
                        }
                    }
                        push(&s,c[i]);

                    break;
                }
                case'-':
                {
                    while(s.top>=0)
                    {
                        if(s.a[s.top]=='(')
                        {
                            break;
                        }

                        else
                        {
                            x=pop(&s);
                            count++;
                            d[count]=x;
                        }
                    }
                        push(&s,c[i]);

                    break;
                }
                case (')'):
                {
                    while(s.top>=0)
                    {
                        if(s.a[s.top]=='(')
                        {
                            x=pop(&s);
                            break;
                        }
                        else
                        {
                            x=pop(&s);
                            count++;
                            d[count]=x;

                        }

                    }
                    x=pop(&s);
                    count++;
                    d[count]=x;
                    break;
                }
                default:
                {
                    printf("\nThe character is neither an operator nor an operand\nCannot be converted\n\n");
                    flag=1;
                    break;
                }

            }
            if(flag==1)
                break;
        }

    }

    if((flag==0))
    {
        while(s.top>=0)
        {
            x=pop(&s);
            count++;
            d[count]=x;

        }
        printf("\n\nThe postfix expression is:\n");
        for(int i=0;i<=count;i++)
        printf("%c ",d[i]);
    }
    else
        printf("\nThe given expression was not correct\n");
    return(0);
}
