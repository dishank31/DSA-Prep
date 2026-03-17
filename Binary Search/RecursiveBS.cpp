#include<bits/stdc++.h>

using namespace std;

bool rec_bin_search(vector<int> &arr, int low, int high, int target)
{
    if(low <= high)     // While condition wont be coming because recursion apna answer khud le aata hain
    {
        int mid = (low + high - low) / 2;           // To avoid mid overflow (Useful for large testcases)
        if(target == arr[mid]) return true;
        else if(target > arr[mid]) return rec_bin_search(arr, mid+1, high, target);    // Also idhr return nahi kiya tha function which is a mistake kyu ki agar return nahi kiya toh tera answer kho jayega
        else return rec_bin_search(arr, low, mid-1, target);
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
    bool res = rec_bin_search(arr, 0, n-1, target);
    if(res == true) cout << "Element Found";
    else cout << "Element not found"; 
    return 0;
}