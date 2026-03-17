#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());

    while(Q--)
    {
        int target;
        cin >> target;

        int low = 0, high = N-1;

        int flag = 0;
        while(low <= high)
        {
            int mid = low + ((high - low) / 2);
            if(arr[mid] == target)
            {
                flag = 1;
                break;
            }
            else if(arr[mid] < target) low = mid + 1;
            else high = mid - 1;
        }

        if(flag == 1) cout << "found" << endl;
        else cout << "not found" << endl;
        
    }
}

