#include<stdio.h>
#define MAX 100

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

int main()
{
    int rod_length, rod_price[MAX], optimal_price[MAX], i, j, k, detMaxArray[MAX];

    printf("Enter the rod length: ");
    scanf("%d",&rod_length);

    for(i=1;i<=rod_length;i++)
    {
        printf("Enter price for length %d :",i);
        scanf("%d",&rod_price[i]);
    }

    optimal_price[1] = rod_price[1];

    for(i=2;i<=rod_length;i++)
    {
        detMaxArray[0]=i*rod_price[1];
        detMaxArray[i] = rod_price[i];
        for(k=1;k<i;k++)
        {
            detMaxArray[k]=rod_price[k]+optimal_price[i-k];
        }
        optimal_price[i]=return_max(detMaxArray,i);
    }

    for(i=1;i<=rod_length;i++)
        printf("\nOptimal Maximum price for rod length %d is: %d",i,optimal_price[i]);
}
