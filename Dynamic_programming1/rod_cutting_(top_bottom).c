#include<stdio.h>
int c[100];
int detmaxarray[100];
int v[100];
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


int setC(int *v, int n)
{
    int i,t;
    detmaxarray[0]=n*v[1];
    detmaxarray[n]=v[n];
    for(i=1;i<n;i++)
    {
        if(c[n-i]<=0)
        {
            c[n-i]=setC(v,n-i);
        }
        else
        {
            detmaxarray[i]=v[i]+c[n-i];
        }
    }
    c[n]=return_max(detmaxarray,n);

}
int main()
{
    int n,i;
    printf("Enter the rod length: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("Enter price for length %d :",i);
        scanf("%d",&v[i]);
    }

    setC(v,n);

    for(i=1;i<=n;i++)
        printf("\nOptimal Maximum price for rod length %d is: %d",i,c[i]);
}
