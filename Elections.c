#include <stdio.h>

int main()
{
    int n,t,i,j,l,k,ones,tens;
    printf("\nEnter the number of students and the number of queries\n");
    scanf("%d%d",&n,&t);
    int a[t];
    int b[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
    }
    printf("\nEnter the queries\n");
    for(i=0;i<t;i++)
    {
        scanf("%d ",&a[i]);
    }
    for(i=0;i<t;i++)
    {
        if(a[i]/100==1)
        {
            tens=a[i]/10-10;
            ones=a[i]%10;
            b[tens-1][ones-1]=1;
            b[tens-1][tens-1]=0;
            for(j=0;j<n;j++)
            {
                if(b[j][tens-1]==1)
                {
                    for(k=0;k<n;k++)
                    {
                        b[j][k]=b[tens-1][k];

                    }
                }
            }

        }

        else if(a[i]/10==2)
        {
            ones=a[i]%10;
            for(j=0;j<n;j++)
            {
                if(b[ones-1][j]==1)
                printf("%d ",j+1);
            }
            printf("\n");
        }
        for(l=0;l<n;l++)
        {
            for(k=0;k<n;k++)
            {
                printf("%d ",b[l][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    return 0;
}
