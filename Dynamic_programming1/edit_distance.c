#include<stdio.h>
#include<string.h>
char string1[100],string2[100];

int min(int x,int y, int z)
{
    //printf("%d %d %d then",x,y,z);
    if((x<=y)&&(x<=z))
        return 1;
    else if((y<=z)&&(y<=x))
        return 2;
    else return 3;
}
int main()
{
    int i,j,len1,len2,len3,t;

    printf("Enter two string: ");
    scanf("%s%s",string1,string2);
    len1=strlen(string1);
    len2=strlen(string2);

    int ed[len1+1][len2+1];
    int arrow[len1+1][len2+1];

    for(j=0;j<=len2;j++)
        {
            for(i=0;i<=len1;i++)
            {
                arrow[i][j]=0;
            }
        }

    for(i=0;i<=len1;i++)
    {
        ed[i][0]=i;
        arrow[i][0]=1;
    }

    for(j=0;j<=len2;j++)
    {
        ed[0][j]=j;
        arrow[0][j]=3;
    }

    arrow[0][0]=0;


    for(j=1;j<=len2;j++)
    {
        for(i=1;i<=len1;i++)
        {
            if(string1[i-1]==string2[j-1])
            {
                ed[i][j]=ed[i-1][j-1];
            }
            else
            {
                t=min(ed[i-1][j],ed[i-1][j-1],ed[i][j-1]);
                if(t==1) ed[i][j]=ed[i-1][j]+1;
                if(t==2) ed[i][j]=ed[i-1][j-1]+1;
                if(t==3) ed[i][j]=ed[i][j-1]+1;

                arrow[i][j]=t;
                //printf("%d %d %d %d %d     ",ed[i-1][j],ed[i-1][j-1],ed[i][j-1],t,ed[i][j]);
            }


        }
    }
        /*for(j=0;j<=len2;j++)
        {
            for(i=0;i<=len1;i++)
            {
                printf("%d ",ed[i][j]);
            }
            printf("\n");
        }*/

        /*printf("\n");printf("\n");printf("\n");
        for(j=0;j<=len2;j++)
        {
            for(i=0;i<=len1;i++)
            {
                printf("%d ",arrow[i][j]);
            }
            printf("\n");
        }*/

        i=len1;
        j=len2;

        printf("Total %d moves needed to get 1st string from 2nd string\nFollowing the instruction from bottom to top\n\n",ed[i][j]);
        while((i+j)!=0)
        {
            //printf("i=%d, j=%d\n",i,j);
            if(arrow[i][j]==1)
            {
                printf("Insert %c after the position %d of 2nd string\n",string1[i-1],i-1);
                i--;
            }
            else if(arrow[i][j]==2)
            {
                printf("Replace %c by %c\n",string2[j-1],string1[i-1]);
                i--;
                j--;
            }
            else if(arrow[i][j]==3)
            {
                printf("Delete %c from 2nd string\n",string2[j-1]);
                j--;
            }
            else
            {
                i--;
                j--;
            }
        }
}
