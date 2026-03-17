#include<bits/stdc++.h>
using namespace std;
#define int long long

// Hypothesis: Print the numbers in even indices in a reversed order.

void print(vector<int> &arr, int N, int i)
{
    if(i >= N) return;      // base case
    
    // induction
    print(arr, N, i+2);
    cout << arr[i] << " ";
}

signed main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    print(arr, N, 0);
}