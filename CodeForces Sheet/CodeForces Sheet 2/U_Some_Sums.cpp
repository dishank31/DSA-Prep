#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    int maxSum = 0;

    for(int i=1 ; i<=N ; i++)
    {
        int temp = i, sum = 0;
        while(temp > 0)
        {
            int digit = temp % 10;
            sum += digit;
            temp /= 10;
        }
        if(sum >= A && sum <= B) maxSum += i;
    }

    cout << maxSum;
    return 0;
}