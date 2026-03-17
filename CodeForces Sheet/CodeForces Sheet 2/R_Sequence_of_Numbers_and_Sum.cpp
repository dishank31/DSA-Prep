#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool condition = true;
    
    while(condition)
    {
        int M, N;
        cin >> M >> N;
        if(N > 0 && M > 0)
        {
            int sum = 0;

            for(int i = min(M,N) ; i<= max(M,N) ; i++)
            {
                sum += i;
            }

            for(int i = min(M,N) ; i<= max(M,N) ; i++) cout << i << " ";
            cout << "sum =" << sum << endl;
        }  
        else condition = false;
    }
    return 0;
}