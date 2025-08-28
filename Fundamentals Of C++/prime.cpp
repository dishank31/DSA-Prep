// Check if number is prime or not

#include<iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter a number : ";
    cin >> n;

    int count = 0;
    
    if(n == 0 || n == 1) cout << n << "is neither prime nor composite"<< endl;
    
    for(int i=2 ; i<=n ; i++ )
    {
        if( n%i == 0) 
        {
            count++;
        }
    }

    if(count > 1) cout << n << " is a composite number"<< endl;
    else cout << n << " is a prime number" << endl;

    return 0;
}