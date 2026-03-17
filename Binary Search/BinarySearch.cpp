#include<bits/stdc++.h>

using namespace std;

bool bin_search(vector<int> &arr, int low, int high, int target)
{   
    while(low <= high)  // To check for Search Space exhaustion
    {
        int mid = (low + high) / 2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " spaced integers in sorted fashion : ";
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    int target;
    cout << "Enter number u want to search : ";
    cin >> target;
    bool res = bin_search(arr, 0, n-1, target);
    if(res == true) cout << "Element Found";
    else cout << "Element not found"; 
    return 0;
}