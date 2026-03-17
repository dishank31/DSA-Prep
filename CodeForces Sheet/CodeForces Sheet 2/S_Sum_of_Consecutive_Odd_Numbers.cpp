#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int X, Y;
        cin >> X >> Y;

        int i = min(X,Y);
        if(i%2==0) i += 1;
        else i += 2;
        int sum = 0;

        for( ; i<max(X,Y) ; i+=2) sum += i;

        cout << sum << endl;
    }
    return 0;
}