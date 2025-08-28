#include<iostream>

using namespace std;

int main()
{
    int marks;
    cout << "Enter your marks : ";
    cin >> marks;

    if(marks<25) cout << "Back aa gayi Enjoy!!";
    else if(marks<=44) cout << "Grade : E";
    else if(marks<=49) cout << "Grade : D";
    else if(marks<=59) cout << "Grade : C";
    else if(marks<=79) cout << "Grade : B";
    else cout << "Grade : A";

    return 0;
}