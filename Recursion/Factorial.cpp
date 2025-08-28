#include<bits/stdc++.h>

using namespace std;

// Functional Recursion
int factorial(int n)
{
    if(n<2) return 1;
    else return (n * factorial(n-1));
}

int main()
{
    int n;
    cout << "Enter number to find out its factorial : ";
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}