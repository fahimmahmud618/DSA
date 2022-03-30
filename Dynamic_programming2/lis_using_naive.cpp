#include <iostream>
using namespace std;
#define MAX 100
int arr[MAX], length[MAX], sub_sequence[MAX], reverse[MAX],t=0;

bool max(int x, int y)
{
    if(x>=y)
        return true;
    else
        return false;
}

int ret_maxpos(int size)
{
    int max = length[0];
    int pos=0;
    for(int i=0;i<size;i++)
    {
        if(max<length[i])
        {
            max=length[i];
            pos=i;
        }
    }
    cout<<"Maximum at the pos: "<<pos;
    return pos;
    
}
int backtrack(int pos)
{
    
    reverse[t]=arr[pos];
    if(length[pos]==-1)
    {
        cout<<reverse[t];
        return t;
    }
    
    cout<<reverse[t]<<" ";
    pos = sub_sequence[pos];
        t++;
        backtrack(pos);
    return t;
}

int main()
{
    int n,i,j;
    printf("Total element in the array is: ");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        length[i]=1;
    }
    length[0]=-1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                cout<<"hoise";
                if(max(length[j]+1,length[i])) //modification
                {
                    cout<<"__HA__";
                    length[i]=length[j]+1;
                    sub_sequence[i]=j;
                }
                
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t%d",arr[i],length[i],sub_sequence[i]);
    }
    
    cout<<"value of t : "<<backtrack(ret_maxpos(n));
    
    return 0;
}
