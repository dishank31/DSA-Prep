#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int N;
    cin >> N;

    vector<vector<int>> matrix(N, vector<int>(N, 0));

    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<N ; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int sum1 = 0;
    for(int i=0 ; i<N ; i++)        // Adding Diagonal Elements
    {
        int j = i;
        sum1 += matrix[i][j];
    }

    int sum2 = 0;
    for(int i=0 ; i<N ; i++)
    {
        int j = N-i-1;
        sum2 += matrix[i][j]; 
    }
    cout << abs(sum1 - sum2);
}