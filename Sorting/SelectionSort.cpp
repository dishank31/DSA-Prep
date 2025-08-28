#include<bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int>& arr, int n)
{
    for(int i=0 ; i<n-1 ; i++)
    {
        int min = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
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
    SelectionSort(arr, n);
    for(int i=0 ; i<arr.size() ; i++) cout << arr[i] << " ";
    return 0;
}