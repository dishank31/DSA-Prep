#include<bits/stdc++.h>
using namespace std;

vector<bool> seive(int N)
{
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2 ; i*i<=N ; i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i ; j<=N ; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    return isPrime;
}

int main()
{
    int N;
    cin >> N;

    vector<bool> Primes = seive(N);
    for(int i=2 ; i<=N ; i++)
    {
        if(Primes[i]) cout << i << " ";
    }
    return 0;
}