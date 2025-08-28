#include<bits/stdc++.h>

using namespace std;

void Print(int n , int i)
{
    if(i>n) return;
    else
    {
        cout << i << endl;
        Print(n,i+1);
    }
}

void Print1(int n , int i)
{
    if(i<=0) return;
    else
    {
        cout << i << endl;
        Print1(n,i-1);
    }
}

int main()
{
    int n , i=1;
    cout << "Enter number till you want to print : ";
    cin >> n;
    Print(n,i);
    cout << endl;
    Print1(n,n);
    return 0;
}