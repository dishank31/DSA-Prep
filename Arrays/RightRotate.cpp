#include<bits/stdc++.h>

using namespace std;

void RightRotate(vector<int>& arr, int n, int k)
{
    reverse(arr.begin(), arr.begin()+(n-k));
    reverse(arr.begin()+(n-k), arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers while giving space : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter number of steps for rotation : ";
    cin >> k;
    RightRotate(arr, n, k);
    for(auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}