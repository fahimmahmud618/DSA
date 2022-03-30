#include<stdio.h>
int min(int x,int y)
{
    if(x<=y)
        return x;
    else
        return y;
}
int main()
{
    int n_coin, m,i,j;
    printf("How many coins are there: ");
    scanf("%d",&n_coin);

    int coin[n_coin];
    printf("Enter the value of coins separated with space: ");
    for(i=0;i<n_coin;i++)
        scanf("%d",&coin[i]);

    printf("Enter the amont of money: ");
    scanf("%d",&m);

    int a[m+1];
    int b[m+1];

    a[0]=0;
    b[0]=0;
    for(i=1;i<=m;i++)
    {
        a[i]=50000;
        b[i]=-1;
    }
    for(j=0;j<n_coin;j++)
    {
        for(i=0;i<=m;i++)
        {
            if(i>=coin[j])
            {
                a[i]=min(a[i],1+a[i-coin[j]]);
                b[i]=j;
            }
        }
    }

    /*for(i=0;i<=m;i++)
    {
        printf("%d %d\n",a[i],b[i]);
    }*/

    printf("\n\nCoin used: ");
    do
    {
        printf("Coin %d, ",coin[b[m]]);
        m = m-coin[b[m]];
    }while(m!=0);

    printf("\n\n");
}
