#include<iostream>
#include<vector>
using namespace std;
#define int long long 

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp(high - low + 1);
    int left = low, right = mid+1;
    int idx = 0;

    while(left <= mid && right <= high)         // anyone of the array will exhaust and we will left with some candidates in non-exhausted array
    {
        if(arr[left] <= arr[right])
        {
            temp[idx] = arr[left];
            left++;
            idx++;
        }
        else
        {
            temp[idx] = arr[right];
            right++;
            idx++;
        }
    }

    while(left <= mid)          // Either this or the next loop wil work
    {
        temp[idx] = arr[left];
        idx++;
        left++;
    }

    while(right <= high)
    {
        temp[idx] = arr[right];
        idx++;
        right++;
    }

    for(int i=low ; i<=high ; i++)
    {
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector<int> &arr, int low, int high)
{
    if(low >= high) return;

    int mid = low + (high - low) / 2;
    MergeSort(arr, low, mid);       // Sort the left halves first for each subarray 
    MergeSort(arr, mid+1, high);    // Then Right halves
    Merge(arr, low, mid, high);     // Then merge both of them as per code we sort while merging    
}   

signed main()
{
    int N;
    cin >> N;

    vector<int> arr(N);
    for(int i=0 ; i<N ; i++) cin >> arr[i];

    MergeSort(arr, 0, N-1);

    for(auto it : arr) cout << it << " ";
}