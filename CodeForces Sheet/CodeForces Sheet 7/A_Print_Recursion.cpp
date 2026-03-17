#include<bits/stdc++.h>
using namespace std;

void print(int N)
{
    if(N == 0) return;
    cout << "I love Recursion" << endl;
    print(N-1);
}

int main()
{
    int N;
    cin >> N;

    print(N);
    return 0;
}