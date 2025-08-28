#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// void Reverse(vector<int> &arr , int low , int high)     // Here dont pass the array by value pass it by reference
// {
//     if(low>=high) return;
//     swap(arr[low],arr[high]);
//     Reverse(arr , low+1 , high-1);
// }

void Reverse(vector<int> &arr , int i , int n)
{
    if(i >= (n/2)) return;
    swap(arr[i] , arr[n-i-1]);
    Reverse(arr , i+1 , n);
}    

int main()
{
    int n;
    cout << "How many numbers do you want : ";
    cin >> n;
    cout << "Start entering numbers : " << endl;
    vector<int> arr(n,0);
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    Reverse(arr , 0 , n);
    for(int i=0 ; i<n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}