#include<bits/stdc++.h>

using namespace std;

void BubbleSort(vector<int> &arr, int n)
{
    for(int i=n-1 ; i>0 ; i--)
    {
        int didSwap = 0;                        // Modification for Best Case
        for(int j=0 ; j<i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;          // This condition only applies when the input is in ascending order improving our time complexity
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " spaced numbers : ";
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    BubbleSort(arr, n);
    for(int i=0 ; i<arr.size() ; i++) cout << arr[i] << " ";
    return 0;
}