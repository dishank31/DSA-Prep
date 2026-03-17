#include<bits/stdc++.h>
using namespace std;
#define int long long

int largest(vector<int> &arr, int i, int large)
{
    if(i == arr.size()) return large;       // base case

    //Induction
    if(arr[i] > large) large = arr[i];
    return largest(arr, i+1, large);
}

signed main()
{
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    int ans = largest(arr, 0, arr[0]);
    cout << ans;
}