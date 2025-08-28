#include<iostream>
#include<vector>

using namespace std;

void InsertionSort(vector<int> &arr, int n)
{
    for(int i=0 ; i<n ; i++)
    {
        int j = i;
        while(j>0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1] , arr[j]);
            j--;
        }
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
    InsertionSort(arr, n);
    for(int i=0 ; i<arr.size() ; i++) cout << arr[i] << " ";
    return 0;
}