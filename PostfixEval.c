#include<stdio.h>
#include<string.h>
struct stack
{
    int top;
    int a[20];
};

void push(struct stack *p,int x)
{
    p->top++;
    p->a[p->top]=x;

};

int pop(struct stack *p)
{
    int x=p->a[p->top];
    p->top--;
    return(x);
};

int main()
{
    struct stack s;
    s.top=-1;
    int i,opr1,opr2,opr,flag=0;
    printf("\nEnter the post fix expression to be evaluated\n");
    char c[25];
    scanf("%s",&c);
    printf("\n\n");
    for(i=0;i<strlen(c);i++)
    {
        if((48<=c[i])&&(c[i]<=57))
        {
            push(&s,c[i]-48);
        }
        else
        {
            opr2=pop(&s);
            opr1=pop(&s);
            switch(c[i])
            {
                case '+':
                    {
                        opr=opr1+opr2;
                        push(&s,opr);
                        break;
                    }
                case '-':
                    {
                        opr=opr1-opr2;
                        push(&s,opr);
                        break;
                    }
                case '*':
                    {
                        opr=opr1*opr2;
                        push(&s,opr);
                        break;
                    }
                case '/':
                    {
                        opr=opr1/opr2;
                        push(&s,opr);
                        break;
                    }
                default:
                    printf("\nThe character %c is not an operator\n",c[i]);
                    flag=1;
                    break;

            }
        }


    }
    int val;
    val=pop(&s);
    if(s.top==-1&&flag==0)
        printf("\nThe value of the expression is %d\n",val);
    else
        printf("\nThe expression was incorrect\n");

    return(0);
}
