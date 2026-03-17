#include<bits/stdc++.h>
using namespace std;
#define int long long

void Print(int N, int i)
{
    if(i > N) return;
    else 
    {
        cout << i << endl;
        Print(N, i+1);
    }
}

signed main()
{
    int N;
    cin >> N;
    Print(N,1);   
}