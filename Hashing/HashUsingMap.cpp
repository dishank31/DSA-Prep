#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    cout << "Start entering numbers : ";
    for(int i=0; i<n ; i++)
    {
        cin >> arr[i];
    }

    // Pre-compute
    map<int, int> mpp;
    for(int i=0 ; i<n ; i++)
    {
        mpp[arr[i]]++;
    }

    // To find out that map stores everything in sorted order
    for(auto it : mpp)
    {
        cout << it.first << " => " << it.second << endl;
    }

    int q;
    cout << "Enter how many queries : ";
    cin >> q;
    while(q--)
    {
        int num;
        cout << "Enter number : ";
        cin >> num;
        cout << mpp[num] << endl;
    }

    return 0;
}