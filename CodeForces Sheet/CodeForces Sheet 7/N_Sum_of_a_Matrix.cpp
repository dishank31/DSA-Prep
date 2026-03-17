#include<bits/stdc++.h>
using namespace std;
#define int long long

void summation(vector<vector<int>> A, vector<vector<int>> B, int R, int C, int i, int j)
{
    if(i >= R && j >= C)
    {
        for(int k=0 ; i<R ; i++)
        {
            for(int m=0 ; j<C ; j++)
            {
                cout << A[k][m];
            }
            cout << endl;
        }
        return;
    }

    while(i < R)
    {
        A[i][j] += B[i][j];  
        summation(A, B, R, C, i+1, 0);
    }

    while(j < C)
    {
        A[i][j] += B[i][j];  
        summation(A, B, R, C, i, j+1);
    }
}

signed main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> A(R, vector<int>(C,0));
    vector<vector<int>> B(R, vector<int>(C,0));

    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<C ; j++)
        {
            cin >> A[i][j];
        }
    }
    
    for(int i=0 ; i<R ; i++)
    {
        for(int j=0 ; j<C ; j++)
        {
            cin >> B[i][j];
        }
    }

    summation(A, B, R, C, 0, 0);
}