#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis: Print a pyramid of height N.

void print(int N, int i)
{
    if(N == 0) return;      // base case

    // Induction
    print(N-1, i+1);
    for(int j=0 ; j<i ; j++) cout << " ";
    for(int k=0 ; k<(2*N-1) ; k++) cout << "*";
    cout << endl;
    
}

signed main()
{
    int N;
    cin >> N;

    print(N, 0);
}