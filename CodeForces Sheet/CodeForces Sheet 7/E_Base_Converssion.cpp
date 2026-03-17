#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis: Print the binary equivalent of N.

void print(int N)
{
    if(N == 0) return;      // Base case
    // Induction
    print(N/2);
    cout << N%2;
}

signed main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;

        if(N == 0) cout << "0"; 
        else print(N);

        cout << endl;
    }
}