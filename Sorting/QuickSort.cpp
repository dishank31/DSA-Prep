#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Hoare Partition
int Partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];       // First element pivot
    int i = low-1;
    int j = high+1;
    while(true)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] >= pivot);

        if(i >= j) return j;

        swap(arr[i] , arr[j]);
    }
}

// Lomuto Partition
// int Partition(vector<int> &arr, int low, int high)
// {
//     int i = low-1;
//     int pivot = arr[high];                  // Even if we dont declare pivot the code runs perfeclty fine by comparing with arr[high] but to increase readability we pivot.

//     for(int j=low ; j<high ; j++)
//     {
//         if(arr[j] <= pivot)         
//         {
//             i++;
//             swap(arr[i] , arr[j]);
//         }
//     }

//     swap(arr[i+1] , arr[high]);

//     return i+1;
// }

void QuickSort(vector<int> &arr, int low, int high)
{
    if(low < high)
    {
        int partition = Partition(arr, low, high);
        QuickSort(arr, low, partition);
        QuickSort(arr, partition+1 , high);
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
    QuickSort(arr, 0, n-1); 
    cout << "Sorted array : ";
    for(int i=0 ; i<n ; i++) cout << arr[i] << " ";
    return 0;
}