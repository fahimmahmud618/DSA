#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
const int INF = 1e+8;
int matrix[MAX][MAX],M[MAX][MAX];


void backtrack(int i, int j)
{
    if(i == j)
    {
        cout<<"M"<<i;
    }
    else
    {
        cout<<"(";
        backtrack(i,M[i][j]);
        backtrack(M[i][j]+1,j);
        cout<<")";
    }
}


int calculate_matrix_table(int p[], int i, int j)
{
    if(matrix[i][j]<INF)
    {
        return matrix[i][j];
    }

    if(i==j)
    {
        matrix[i][j] = 0;
    }
    else
    {
        int median_value;
        for(int k=i;k<j;k++)
        {
            median_value = calculate_matrix_table(p,i,k) + calculate_matrix_table(p,k+1,j) + (p[i-1]*p[k]*p[j]);
            if(median_value<matrix[i][j])
            {
                matrix[i][j] = median_value;
                M[i][j] = k;
            }
        }
    }

    return matrix[i][j];
}

int initialization_matrix(int p[], int n)
{
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            matrix[i][j] = INF;
        }
    }

    return calculate_matrix_table(p,1,n);

}

int main()
{
    //freopen("MCM-input.txt","r",stdin);
    int n,p[MAX];
    cout<<"How many martix: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>p[i];
    }

   cout<<"Total cost "<<initialization_matrix(p,n-1)<<endl;

    backtrack(1,n-1);


}
