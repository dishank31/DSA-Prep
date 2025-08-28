#include<iostream>

using namespace std;

int main()
{
    cout << "   Welcome to temperature convertor !" << endl;
    float fahren;
    cout << "Enter temperature (in Fahrenheit) : ";
    cin >> fahren;

    float celsi;
    celsi = (fahren - 32) / (1.8);
    
    cout << "The temperature (in Celsius) is : " << celsi << endl;

    return 0;
}
