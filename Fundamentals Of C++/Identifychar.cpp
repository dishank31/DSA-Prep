#include<iostream>

using namespace std;

int main()
{
    char ch;
    cout << "Enter any character : ";
    cin >> ch;

    if(ch >= 'A' && ch <= 'Z')
    {
        cout << ch << " is uppercase alphabet" << endl;;
    }

    else if(ch >= 'a' && ch <= 'z')
    {
        cout << ch << " is lowercase alphabet" << endl;;
    }

    else if (ch >=0 && ch <= 9)
    {
        cout << ch << " is numerical value" << endl;
    }

    else return 0;
}