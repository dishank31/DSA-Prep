#include<bits/stdc++.h>
using namespace std;
#define int long long

int fib(int N)
{
    if(N == 0 || N == 1) return 0;
    if(N == 2) return 1;
    return fib(N-1) + fib(N-2);
}

signed main()
{
    int N;
    cin >> N;

    cout << fib(N);
}