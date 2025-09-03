#include<bits/stdc++.h>

using namespace std;

void SelectionSort(vector<int>& arr, int n)
{
    for(int i=0 ; i<n-1 ; i++)
    {
        int min = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j] <= arr[min]) min = j;
        }
        swap(arr[min], arr[i]);
    }
}

void BubbleSort(vector<int>& arr, int n)
{
    for(int i=n-1 ; i>0 ; i--)
    {
        int didswap = 0;                    // If array is in ascending order
        for(int j=0 ; j<i ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                didswap = 1;
            }
        }
        if(didswap == 0)
        {
            cout << "Array is already in ascending order";
            return;
        }
    }
}

void InsertionSort(vector<int>& arr, int n)
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

void Merge(vector<int>& arr, int low, int mid, int high)
{
    vector<int> temp;
    int n = arr.size();
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high)
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
    for(int i=low ; i<high ; i++)
    {
        arr[i] = temp[i-low];
    }
}

void MergeSort(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low) / 2;     // To handle integer overflow
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int LumotoPartition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int j = low - 1;

    for(int i=low ; i<high ; i++)
    {
        if(arr[i] <= pivot)
        {
            j++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j+1], arr[high]);

    return j+1;

}

int HoarePartition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while(true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if(i>=j) return j;

        swap(arr[i], arr[j]);
    }
}

void QuickSort1(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int partition = HoarePartition(arr, low, high);
        QuickSort1(arr, low, partition);
        QuickSort1(arr, partition+1, high);
    }
}

void QuickSort2(vector<int>& arr, int low, int high)
{
    if(low < high)
    {
        int partition = LumotoPartition(arr, low, high);
        QuickSort2(arr, low, partition-1);
        QuickSort2(arr, partition+1, high);
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
    // SelectionSort(arr, n);       O(n^2)
    // BubbleSort(arr, n);          O(n^2) Best : O(n)   
    // InsertionSort(arr, n);       O(n^2) Best : O(n)
    // MergeSort(arr, 0, n);           O(nlogn)
    // QuickSort1(arr, 0, n);
    QuickSort2(arr, 0, n);
    for(int i=0 ; i<arr.size() ; i++) cout << arr[i] << " ";
    return 0;
}