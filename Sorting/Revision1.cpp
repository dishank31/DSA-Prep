#include<bits/stdc++.h>

using namespace std;

void bubblesort(vector<int> &arr, int n)
{
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<i ; j++)
        {
            if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
}

void selectionsort(vector<int> &arr, int n)
{
    for(int i=0 ; i<n-1 ; i++)
    {
        int min = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[min] > arr[j]) min = j;
        }
        swap(arr[i], arr[min]);
    }
}

void insertionsort(vector<int> &arr, int n)
{
    for(int i=0 ; i<n ; i++)
    {
        int j = i;
        while(j>0 && arr[j-1] > arr[j])
        {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

void merge(int low, int mid, int high, vector<int> &arr)
{
    int left = low;
    int right = mid+1;
    vector<int> temp;

    while(left <= mid && right <= high)         // || written this instead of &&
    {
        if(arr[left] < arr[right])
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

    for(int i=low ; i<=high ; i++)      // And here i didnt consider the last element for printing
    {
        arr[i] = temp[i-low];
    }
}

void mergesort(int low, int high, vector<int> &arr)
{
    int mid = (low + high) / 2;
    if(low >= high) return;
    mergesort(low, mid, arr);
    mergesort(mid+1, high, arr);
    merge(low, mid, high, arr);
}

int hoarepartition(int low, int high, vector<int> &arr)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while(i < j)
    {
        do
        {
            i++;
        }
        while(arr[i] < pivot);

        do
        {
            j--;
        }
        while(arr[j] >= pivot);

        if(i < j)
        swap(arr[i], arr[j]);
    }

    return j;
}

void quicksort(int low, int high, vector<int> &arr)
{
    if(low < high)
    {
        int partition = hoarepartition(low, high, arr);
        quicksort(low, partition, arr);
        quicksort(partition+1 , high, arr);
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
    quicksort(0, n, arr);
    for(int i=0 ; i<arr.size() ; i++) cout << arr[i] << " ";
    return 0;
}