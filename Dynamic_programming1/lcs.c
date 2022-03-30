#include<stdio.h>
#include<string.h>
char string1[100],string2[100],substring[100];

int max(int x,int y)
{
    if(x>=y)
        return x;
    else
        return y;
}

int main()
{
    int i,j,len1,len2,len3,t=0;

    printf("Enter two string: ");
    scanf("%s%s",string1,string2);
    len1=strlen(string1);
    len2=strlen(string2);

    int lcs[len1+1][len2+1];

    for(i=0;i<=len1;i++)
    {
        lcs[i][0]=0;
    }

    for(j=0;j<=len2;j++)
    {
        lcs[0][j]=0;
    }

    for(j=1;j<=len2;j++)
    {
        for(i=1;i<=len1;i++)
        {
            if(string1[i-1]==string2[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }


    i=len1;
    j=len2;

    while((i>=0)&&(j>=0))
    {
        //printf("for i=%d and j=%d  ",i,j);
        if(lcs[i][j]==lcs[i-1][j])
        {
            i--;
        }
        else if((lcs[i][j]==lcs[i][j-1]))
        {
            j--;
        }
        else
        {
            substring[t]=string1[i-1];
            t++;
            i--;
            j--;
        }
    }
    len3=strlen(substring);
    printf("The longest substring is of %d char long and it is: ",len3);
    for(i=len3-1;i>=0;i--)
        printf("%c",substring[i]);


}
