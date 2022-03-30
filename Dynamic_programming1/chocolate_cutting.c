#include<stdio.h>
int v[1000][1000];
int c[1000][1000];
int detmaxarray[1000];

int return_max(int *array, int size)
{
    int i,max=-1;
    for(i=0;i<=size;i++)
    {
        if(array[i]>max)
            max=array[i];
    }
    return max;
}

int setC(int m,int n)
{
    //printf("__%d*%d__",m,n);
    int i,j,t=1;
    detmaxarray[0]=(m*n)*v[1][1];
    //detmaxarray[n]=v[m][n];
    for(i=1;i<m;i++)
    {
        if(c[m-i][n]<=0)
        {
            setC(m-i,n);
        }
        else
        {
            detmaxarray[t]=c[n][m-i]+v[n][i];
             //printf(":%d:",detmaxarray[t]);
            t++;
        }

    }

    for(j=1;j<n;j++)
    {
        if(c[m][n-j]<=0)
        {
            setC(m,n-j);
        }
        else
        {
            detmaxarray[t]=c[n-j][m]+v[j][m];
            //printf(":%d:",detmaxarray[t]);
            t++;
        }
    }
    detmaxarray[t]=v[n][m];

    c[n][m]=return_max(detmaxarray,t);


}

int main()
{
    int n,m,i,j,k;

    printf("Enter the value of m: ");
    scanf("%d",&m);
    printf("Enter the value of n: ");
    scanf("%d",&n);

    int r=1,col=1;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("Enter price for %d*%d sized chocolate: ",i,j);
            scanf("%d",&v[i][j]);
        }
    }
    c[1][1]=v[1][1];

    setC(m,n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("\nMaximum benifit for %d*%d size is %d ",i,j,c[i][j]);

        }
    }


}
