#include<bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    for(int i=0 ; i<arr.size() ; i++)
    {
        for(int j=0 ; j<arr[i] ; j++)
        {
            cout << S;
        }
        cout << endl;
    }
    return 0;
}