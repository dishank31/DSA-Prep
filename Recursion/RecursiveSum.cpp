#include<iostream>

using namespace std;

int sum = 0;

// Paramaterised Recursion
void Sum(int n ,int sum)
{
    if(n<1)
    {
        cout << sum << endl;
        return;
    }
    else
    {
        Sum(n-1,sum+n);
    }
}

// Functional Recursion
int Add(int n)
{
    if(n==0) return 0;
    else return (n + Add(n-1));
}

int main()
{
    int n , sum;
    cout << "Enter number till you want the sum : ";
    cin >> n;
    // Sum(n,0);
    cout << Add(n) << endl;
    return 0;
}