#include<iostream>

using namespace std;

void GCD(int m , int n)
{
    for(int i=1 ; i<=min(m,n) ; i++)
    {
        if(m % i == 0 && n % i == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n , m;
    cout << "Enter two numbers to calculate their greatest common divisor : ";
    cin >> m >> n;
    GCD(m,n);
    return 0;
}