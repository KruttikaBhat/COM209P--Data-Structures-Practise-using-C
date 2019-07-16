#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void fre(int B,int n);
void MinFre(int B,int n)
 {
    int d[n],i,j;
    d[0]=1;
    for(i=1;i<n;i++)
        d[i]=d[i-1]+rand()%25;

    printf("The selected denominations are:\n");
    for(i=0;i<n;i++)
        printf("%d ",d[i]);


    int a[n],b[n],s[n],fre;
    for(i=n-1;i>=0;i--)
    {
        a[i]=B/d[i];
        b[i]=B%d[i];
        s[i]=a[i]+b[i];
    }
    int min=s[n-1],minpos=n-1;
    for(i=n-2;i>=0;i--)
    {
        if(s[i]<min)
        {
            min=s[i];
            minpos=i;
        }
    }

    for(i=minpos;i>=0;i--)
    {
        fre=0;
        while(B>=d[i])
        {
            B=B-d[i];
            fre++;
        }
        if(fre!=0)
            printf("\n%d\t%d",d[i],fre);
    }

}


int main()
{
    srand(time(NULL));
    int B,n;
    printf("Enter an amount and the number of denominations\n");
    scanf("%d%d",&B,&n);
    MinFre(B,n);
    fre(B,n);


    return(0);
}

void fre(int B,int n)
{
    int a[n][n],q,x,i,j,freq[n],minfre,d[n];
    printf("\nEnter the denominations\n");
    for(i=0;i<n;i++)
        scanf("%d",&d[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j]=0;
    for(i=n-1;i>=0;i--)
    {
        q=0;
        x=B;
        for(j=i;j>=0;j--)
        {
            if(x>=d[j])
            {
                a[i][j]=x/d[j];
                q=x/d[j]+q;
                x=x%d[j];
            }

        }
         freq[i]=q;
    }
    minfre=freq[n-1];
    for(i=0;i<n;i++)
        if(freq[i]<minfre)
            minfre=freq[i];
    printf("\ndenomination   frequency\n");
    for(i=0;i<n;i++)
    {
        printf("\n\n\n");
        if(freq[i]==minfre)
            for(j=0;j<n;j++)
                if(a[i][j]>0)
                    printf("%d      %d\n",d[j],a[i][j]);

    }

}
