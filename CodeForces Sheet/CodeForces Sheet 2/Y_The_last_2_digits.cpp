#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    long long digits = ((A%100) * (B%100) * (C%100) * (D%100)) % 100; // Tip : Keep only the last two digits of every number because uska hii need hain
    if(digits < 10) cout << "0" << digits;
    else cout << digits;
    return 0;
}