#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

// bool IsPrime(int n)
// {
//     for(int i=2 ; i*i<=n ; i++)
//     {
//         if(n % i == 0)  return false;
//     }
//     return true;
// }

vector<bool> Sieve(int n)
{
    vector<bool> IsPrime(n+1 , true);
    IsPrime[0] = IsPrime[1] = false;

    for(int p=2 ; p*p<=n ; p++)
    {
        if(IsPrime[p])
        {
            for(int i=p*p ; i<=n ; i+=p)
            {
                IsPrime[i] = false;
            }
        }
    }
    return IsPrime;
}

int main()
{
    int n;
    cin >> n;
    // if(IsPrime(n)) cout << "Prime number" << endl;
    // else cout << "Composite number" << endl;
    vector<bool> primes = Sieve(n);
    cout << "Prime numbers up to " << n << " are:\n";
    for(int i = 2; i <= n; i++) {
        if(primes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}