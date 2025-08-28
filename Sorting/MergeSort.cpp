#include<iostream>
#include<vector>

using namespace std;

void Merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high)             // && is used because both conditions must be true if either one fails it should stop/break
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low ; i<=high ; i++)          // This loop is for inserting the elements in main array.
    {
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);            // Dont miss out mid+1 else infinte loop mein chale jaoge
        Merge(arr, low, mid, high);
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
    MergeSort(arr, 0, n-1);
    for(int i=0 ; i<n ; i++) cout << arr[i] << " ";
    return 0;
}