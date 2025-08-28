#include<bits/stdc++.h>

using namespace std;

void Print (int n , int i)
{
    if(i>n) return;
    else
    {
        cout << "Dishank" << endl;
        Print(n,i+1);
    }
}

int main()
{
    int n , i=1;
    cout << "Enter how many times you have to print the name : ";
    cin >> n;
    Print(n,i);
    return 0;
}