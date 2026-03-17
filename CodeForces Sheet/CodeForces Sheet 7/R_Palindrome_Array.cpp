#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis: Determine if it's palindrome or not.

bool Palindrome(vector<int> &arr, int i, int j)
{
    if(i >= j) return true;     // base case

    //Induction
    if(arr[i] == arr[j]) return Palindrome(arr, i+1, j-1);
    else return false;
}

signed main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    if(Palindrome(arr, 0, N-1)) cout << "YES";
    else cout << "NO";
}