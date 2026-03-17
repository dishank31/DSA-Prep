#include<bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    vector<bool> isLucky(B+1, true);
    bool found = false;
    
    for(int i=A ; i<=B ; i++)
    {
        int temp = i;
        while(temp>0)
        {
            int digit = temp % 10;
            if(digit != 4 && digit != 7) isLucky[i] = false;
            temp /= 10; 
        }
        if(isLucky[i]) cout << i << " ";
        if(isLucky[i]) found = true;
    }

    if(!found) cout <<"-1";    
    return 0;
}