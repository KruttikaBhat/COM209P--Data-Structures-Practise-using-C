#include<stdio.h>
#include<stdlib.h>

struct heap
{
    int size;
    int a[50];
};

struct heap H;


void insert(int x)
{
    H.size++;
    H.a[H.size]=x;
    int i=H.size,temp;
    while(i/2>=1)
    {
        if(H.a[i]>H.a[i/2])
        {
            temp=H.a[i];
            H.a[i]=H.a[i/2];
            H.a[i/2]=temp;
        }
        i=i/2;
    }
}

int delete()
{
    int x=H.a[1];
    H.a[1]=H.a[H.size];
    H.size--;
    int i=1,temp,max;
    while((2*i<=H.size)&&((H.a[2*i]>H.a[i])||(H.a[2*i+1]>H.a[i])))
    {
        if(H.a[2*i+1]>H.a[2*i])
            max=2*i+1;
        else
            max=2*i;
        temp=H.a[i];
        H.a[i]=H.a[max];
        H.a[max]=temp;
        i=max;
    }
    return(x);
}

int main()
{
    int c,x,i,s;
    int a[50];
    H.size=0;
    while(c!=5)
    {
        printf("\nEnter one of the below options:\n1.Insert\n2.Delete\n3.Display\n4.Sort\n5.exit\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            printf("\nEnter a number\n");
            scanf("%d",&x);
            insert(x);
            break;
        case 2:
            delete();
            break;
        case 3:
            for(i=1;i<=H.size;i++)
            {
                printf("%d ",H.a[i]);
            }
            break;
        case 4:
            s=H.size;
            for(i=H.size-1;i>=0;i--)
            {
                x=delete();
                a[i]=x;
            }
            printf("\nAfter sorting \n");

            for(i=0;i<s;i++)
            {
                printf("%d ",a[i]);
            }

            break;
        case 5:
            break;
        }

    }

return(0);
}
