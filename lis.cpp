#include <iostream>
using namespace std;
#define MAX 100
int arr[MAX], length[MAX], sub_sequence[MAX];

bool max(int x, int y)
{
    if(x>=y)
        return true;
    else
        return false;
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

    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                cout<<"hoise";
                if(max(arr[j],arr[i]))
                {
                    cout<<"__HA__";
                    length[i]=length[j]+1;
                    sub_sequence[i]=j;
                }
                
            }
        }
    }
    
    for(i=1;i<n;i++)
    {
        printf("%d\t%d\t%d\n",arr[i],length[i],sub_sequence[i]);
    }
    return 0;
}
