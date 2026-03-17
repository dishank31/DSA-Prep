#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i=0 ; i<N ; i++) cin >> arr[i];

        int opr = 0;
        for(int i=0 ; i<N-1 ; i++)
        {
            if(arr[i+1] == arr[i] || arr[i+1] == (7 - arr[i])) opr++;
        }

        cout << opr << endl;
        
    }
}