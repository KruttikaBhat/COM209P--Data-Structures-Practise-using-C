#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int N=20;
void celeb2(int a[][N],int n);
void celeb1(int a[][N],int p[N],int n);
void celeb3(int a[][N],int n);
void celebnby2(int a[][N],int n);

int main()
{
    srand(time(NULL));
    int n,i,j;
    printf("Enter the number of people\n");
    scanf("%d",&n);
    int a[N][N];
    int p[N];
    for(i=0;i<n;i++)
        p[i]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j]=rand()%2;
    }

    srand(time(NULL));
    int c=rand()%n;
    for(int j=0;j<n;j++)
        a[c][j]=0;
    for(int i=0;i<n;i++)
        a[i][c]=1;

    for(int i=0;i<n;i++)
        a[i][i]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

   printf("\n%d\n",c+1);


    celeb1(a,p,n);
    celeb2(a,n);
    celeb3(a,n);
    celebnby2(a,n);

    return(0);

}

void celeb1(int a[][N],int p[N],int n)
{
    int i,j,ctr1=n*n;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             if(i==j)
                continue;
             if(a[i][j]==1)
                p[i]=0;
             else if(a[i][j]==0)
                p[j]=0;
        }

    }
    for(i=0;i<n;i++)
        printf("%d ",p[i]);
    for(i=0;i<n;i++)
    {
        ctr1++;
        if(p[i]==1)
        {
            printf("\nThe person %d is the celebrity\n",i+1);
            break;
        }

    }
    printf("\nThe number of comparisons in first case is %d\n",ctr1);

}

void celeb2(int a[][N],int n)
{
    int i,ctr2=0,k=0,l=n-1;
    while(k<l)
    {
        if(a[k][l]==1)
            k++;
        else
            l--;
        ctr2++;
    }
    if(k==l)
    {
        for(i=0;i<n;i++)
        {
            ctr2++;
            if((i!=k)&&((a[i][k]==0)||(a[k][i]==1)))
               {
                   printf("There is no celebrity\n");
                   break;
               }

        }

    }
    if(i==n)
    {
        printf("%d is the celebrity\nThe number of comparisons made in the second case is %d",k+1,ctr2);
    }

}

void celeb3(int a[][N],int n)
{
    int i,j,c,count=0,flag=0,flag2=0;
    for(i=0,j=1;i<n,j<n;)
    {
        if(a[i][j]==0)
        {
            j++;
            count++;
            if(j==n-1)
            {
                flag=1;
                c=i;
                break;
            }
        }
        else if(a[i][j]==1)
        {

            i=j;
            j++;
            count++;
        }

    }
    if(flag==1)
        for(i=0;i<n;i++)
        {
            count++;
            if(a[i][c]==0)
            {
                flag2=1;
                break;
            }
        }
    printf("\nflag=%d flag2=%d\n",flag,flag2);
    if(flag==1&&flag2==0)
        printf("\n%d is the celebrity!!! The number of counts in the 3rd case is %d\n",c+1,count);
    else if(flag==0||flag2==1)
        printf("\nNo celebrity\n");
    return;
}


void celebnby2(int a[][N],int n)
{
    int b[n*n][2],count=0,flag;
    int p[n],i,j;
    for(i=0;i<n;i++)
        p[i]=1;
    for(i=0;i<n;i++)
    {
        printf("\n");
        for(j=0;j<n;j++)
        {
           if(a[i][j]==1)
           {
               b[count][0]=i+1;
               b[count][1]=j+1;
               count++;
           }
        }

    }

    for(i=0;i<count;i++)
    {

        printf("\n");
        for(j=0;j<2;j++)
            printf("%d ",b[i][j]);
    }
    for(i=0;i<count;i++)
    {
        if(b[i][0]==b[i][1])
            continue;
         p[b[i][0]-1]=0;
    }

    for(i=0;i<n;i++)
    {
        if(p[i]==1)
            printf("\n%d is the celeb\n",i+1);
    }
}
