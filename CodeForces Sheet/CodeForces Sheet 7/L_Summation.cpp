#include<bits/stdc++.h>
using namespace std;
#define int long long

void summation(vector<int> &arr, int i, int sum)
{
    if(i == arr.size())
    {
        cout << sum;
        return;
    }
    summation(arr, i+1, sum+arr[i]);
}

signed main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    summation(arr, 0, 0);
}