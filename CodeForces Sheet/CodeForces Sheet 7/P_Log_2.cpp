#include<bits/stdc++.h>
using namespace std;
#define int long long

int solve(int N, int count)
{
    if(N == 0 || N == 1) return count;        // Base case
    solve(N/2, count+1);
}

signed main()
{
    int N;
    cin >> N;

    cout << solve(N, 0);
}