#include<iostream>
#include<string>
#include<iomanip>           // Library which includes fixed and setprecision

using namespace std;

int main()
{
    /*
        1)int , long , long long , float , double
        2)string , (getline) :- to print the whole line of input
        3)char
        int = 4 bytes
        long = 8 bytes
        long long = 8 bytes
        float = 4 bytes
        double = 8 bytes
        char = 1 byte
        bool = 1 byte
        string = 24 bytes           
    */ 

    string str;
    cout << "Write a sentence : ";
    getline(cin , str);
    cout << str;

    // A new concept of set precision and fixed
    float a = 1245.4;
    double b = 1245552.3645;
    cout  << endl << fixed << setprecision(4) << a << endl;
    cout << fixed << setprecision(9) << b << endl;
    return 0;
}