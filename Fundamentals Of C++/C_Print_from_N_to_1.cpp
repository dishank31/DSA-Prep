#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis : Print number starting from N till 1

void Print(int N)
{
    if(N == 0) return;      // Base case
    
    else if(N == 1) cout << "1";

    // Induction
    else
    {
        cout << N << " ";
        Print(N-1);
    }
}

signed main()
{
    int N;
    cin >> N;
    Print(N);   
}