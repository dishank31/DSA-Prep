#include<iostream>
#include<cmath>

using namespace std;

void conversion()
{
    int n;
    cout << "Enter a number in binary form : ";
    cin >> n;

    int ans = 0 , i = 0;

    while(n != 0)
    {
        int digit = n % 10;                     // Agar ham yaha pe (bit = n & 1) use krte toh program mein ham binary input de rhe hai toh sys usko as ddecimal treat krta and uska binary nikalke aage procedure krta jo ki wrong hain    
        if(digit == 1)
        {
            ans = ans + (pow(2,i) * digit);
            i++;
        }
        else
        {
            i++;
        }
        n = n / 10;
    }

    cout << "Decimal number to the given binary number is : " << ans << endl;

}

int main()
{
    conversion();
    return 0;
}