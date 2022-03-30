#include <stdio.h>
int c[100][100];
int v[100][100];

int min(int x,int y,int z)
{
    if((x<=y)&&(x<=z))
        return x;
    else if((y<=z)&&(y<=x))
        return y;
    else
        return z;
}

int min_pos(int x,int y,int z)
{
    if((x<=y)&&(x<=z))
        return 1;
    else if((y<=z)&&(y<=x))
        return 2;
    else
        return 3;
}


void print_path(int x, int pos)
{
    int i;
    for(i=1;i<=x;i++)
    {
        if(i==pos)
            printf("^");
        else
            printf("#");
    }
    printf("\n");
}
int main()
{
    int i,j,h,w,min1,pos;

    printf("Enter the hieght and width of the rock: ");
    scanf("%d%d",&h,&w);

    printf("Enter the danger table (top to bottom): \n");
    for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            scanf("%d",&v[i][j]);
        }
    }
    system("cls");
    /*for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            printf("%d   ",v[i][j]);
        }
        printf("\n");
    }*/

    i=2;j=1;
    for(j=1;j<=w;j++)
    {
        c[h][j]=v[h][j];
    }
    for(i=(h-1);i>0;i--)
    {
        for(j=1;j<=w;j++)
        {
            if(j==1)
            {
                c[i][j]=v[i][j] + min(c[i+1][j],c[i+1][j+1],c[i+1][j]);
            }
            else if(j==w)
            {
                c[i][j]=v[i][j] + min(c[i+1][j],c[i+1][j-1],c[i+1][j]);
            }
            else
            {
                c[i][j]=v[i][j] + min(c[i+1][j],c[i+1][j-1],c[i+1][j+1]);
            }

        }
    }

    /*for(i=1;i<=h;i++)
    {
        for(j=1;j<=w;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }*/
    min1=c[1][1];
    pos=1;
    for(j=1;j<=w;j++)
    {
        if(c[1][j]<min1)
        {
            min1=c[1][j];
            pos=j;
        }
    }
    printf("Path to climb the rock\nOptimal path is ^ indicated\n\n");

    print_path(w,pos);

    for(i=1;i<h;i++)
    {
        if(pos==w)
        {
            if(min_pos(c[i+1][pos-1],c[i+1][pos],c[i+1][pos])==1)
            {
                pos--;
            }
            print_path(w,pos);
        }
        else if(pos==1)
        {
            if(min_pos(c[i+1][pos],c[i+1][pos+1],c[i+1][pos+1])==2)
            {
                pos++;
            }
            print_path(w,pos);
        }
        else
        {
            if(min_pos(c[i+1][pos-1],c[i+1][pos],c[i+1][pos+1])==1)
            {
                pos--;
            }
            else if(min_pos(c[i+1][pos-1],c[i+1][pos],c[i+1][pos+1])==3)
            {
                pos++;
            }
            print_path(w,pos);
        }
    }



}


/*
2 8 9 5 8
4 4 6 2 3
5 7 5 6 1
3 2 5 4 8
*/
