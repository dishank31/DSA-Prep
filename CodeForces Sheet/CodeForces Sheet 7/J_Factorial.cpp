#include<bits/stdc++.h>
using namespace std;
#define int long long

int fact(int N, int factorial)
{
    if(N == 0) return factorial;    // base case

    //induction
    return factorial = N * fact(N-1, factorial);
}

signed main()
{
    int N;
    cin >> N;

    if(N == 0) cout << "0";
    else {
        int ans = fact(N, 1);
        cout << ans;
    }
}