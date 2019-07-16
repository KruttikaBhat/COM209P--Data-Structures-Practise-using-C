#include<stdio.h>
int main()
{
    int r,c;
    printf("Enter the number of rows and columns\n");
    scanf("%d%d",&r,&c);
    int a[r][c],i,j,temp[r][c];
    printf("Enter the matrix\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }

     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            temp[i][j]=a[i][j];
    }
     for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            a[j][i]=temp[i][j];
    }
     for(i=0;i<c;i++)
    {
        for(j=0;j<r;j++)
            printf("%d",a[i][j]);
        printf("\n");
    }
return(0);
}
