#include<iostream>
#include<vector>

using namespace std;

void LeftRotate(vector<int>& arr, int n)
{
    int temp = arr[0];
    for(int i=1 ; i<n ; i++)
    {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;    
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " intgers while giving space : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    LeftRotate(arr, n);
    for(auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}