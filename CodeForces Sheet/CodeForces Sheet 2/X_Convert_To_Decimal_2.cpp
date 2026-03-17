#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;
        int ans = 0;
        int final_ans = 0;

        while(N >= 1)
        {
            int binary = N % 2;
            if(binary == 1) ans += (ans * 10) + binary;
            N /= 2;
        }

        int i=0;
        while(ans > 0)
        {
            int digit = ans % 10;
            final_ans += ans * pow(2, i);
            ans /= 10;
            i++;
        }

        cout << final_ans << endl;
    }
    return 0;
}