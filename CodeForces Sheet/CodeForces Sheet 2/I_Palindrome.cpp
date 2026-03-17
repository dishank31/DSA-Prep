#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int ans = 0;
    int reverse = N;

    while(N>0)
    {
        int digit = N % 10;
        ans = (ans * 10) + digit;
        N /= 10;
    }

    if(reverse == ans) cout << ans << endl << "YES" << endl;
    else cout << ans << endl << "NO" << endl;
    return 0;
}