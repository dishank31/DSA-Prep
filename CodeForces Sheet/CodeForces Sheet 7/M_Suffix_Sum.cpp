#include<bits/stdc++.h>
using namespace std;
#define int long long

void suffixsum(vector<int> &arr, int M, int sum)
{
    if(M == arr.size())
    {
        cout << sum;
        return;
    }
    suffixsum(arr, M+1, sum+arr[M]);
}

signed main()
{
    int N, M;
    cin >> N >> M;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    suffixsum(arr, N-M, 0);
}