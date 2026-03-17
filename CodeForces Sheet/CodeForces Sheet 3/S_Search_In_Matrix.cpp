#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> Mat(N, vector<int>(M,0));
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<M ; j++)
        {
            cin >> Mat[i][j];
        }
    }

    int X;
    cin >> X;   

    bool found = false;
    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<M ; j++)
        {
            if(Mat[i][j] == X)
            {
                found = true;
                break;
            }
        }
    }

    if(found) cout << "will not take number";
    else cout << "will take number";
}