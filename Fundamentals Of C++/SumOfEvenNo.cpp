#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter  value of n : ";
    cin >> n;

    int sum = 0;
    int i = 0;

    while(i<=n)
    {
        sum = sum + i;
        i = i + 2;
    }

    cout << "Resultant sum is : " << sum << endl;

    return 0;
}