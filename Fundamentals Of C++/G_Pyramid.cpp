#include<bits/stdc++.h>
using namespace std;
#define int long long

void Print(int N, int i)
{
    if(N == 0) return;      // base case

    // Induction
    for(int j=0 ; j<i ; j++)
    {
        cout << "*";
    }
    cout << endl;
    Print(N-1, i+2);
}

signed main()
{
    int N;
    cin >> N;
    Print(N,1);   
}