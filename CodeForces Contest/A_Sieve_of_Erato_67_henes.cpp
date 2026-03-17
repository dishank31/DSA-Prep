#include<bits/stdc++.h>
using namespace std;;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for(int i=0 ; i<N ; i++) cin >> arr[i];

        bool found = false;

        for(auto x : arr)
        {
            if(x == 67) found = true;
        }

        if(found) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}