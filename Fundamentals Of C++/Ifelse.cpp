//To understand If else statement
#include<iostream>

using namespace std;

int main()
{
    int age;
    cout << "Enter your age : ";
    cin >> age;

    if(age >= 18)
    {
        cout << "Damn!! You are an adult";
    }

    else
    {
        cout << "Grow Up kid";
    }

    return 0;
}