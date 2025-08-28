#include<iostream>
#include<cmath>

using namespace std;

void FirstMethod()
{
    int n, rem, i=0;
    cout << "Enter a decimal number : ";
    cin >> n;
    int res[20];

    while (n)
    {
        rem = n % 2;
        n = n / 2;
        res[i] = rem;
        i++;
    }

    for(int j=i-1 ; j>=0 ; j--)
    {
        cout << res[j];
    
    }
    cout << endl;
}

void CrazyMethod()
{
    int num;
    cout << "Enter a decimal number : ";
    cin >> num;
    float bit , i=0 , ans=0;

    while(num != 0)
    {
        bit = num & 1;
        ans = ans + (bit * pow(10 , i));
        num = num >> 1;
        i++; 
    }

    cout << "Answer is : " << ans << endl;
}

int main()
{
    // FirstMethod();
    CrazyMethod();
    return 0;
}