#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis: Print the digits of N separated by a space.

void print(string S, int i, int n)
{
    if(i >= n) return;      // Base case

    //Induction
    cout << S[i] << " ";
    print(S, i+1, n);
}

signed main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        
        string str = to_string(N);
        int n = str.size();

        print(str, 0, n);

        cout << endl;
    }
}