#include<iostream>

using namespace std;

int main()
{
    int a = 4;
    int b = 7;

    int bitwise_AND = a & b;
    int bitwise_OR = a | b;
    int bitwise_XOR = a ^ b;
    int bitwise_NOT = ~ a;
    int RIGHT_shift = 7 << 2;
    int LEFT_shift = 15 >> 3;

    cout << "AND operation is : " << bitwise_AND << endl;
    cout << "OR operation is : " << bitwise_OR << endl;
    cout << "XOR operation : " << bitwise_XOR << endl;
    cout << "NOT opeartion : " << bitwise_NOT << endl;

    cout << "RIGHT shift : " << RIGHT_shift << endl;
    cout << "LEFT shift : " << LEFT_shift << endl;

    cout << a++ << endl;        //POST increment
    cout << ++a << endl;        //PRE increment
    cout << b-- << endl;        //POST decrement
    cout << --b << endl;        //PRE decrement

    return 0;
}