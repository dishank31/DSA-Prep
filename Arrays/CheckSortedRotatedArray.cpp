#include<iostream>
#include<vector>
#include<array>

using namespace std;

class solution
{
    public:
        bool CheckSortedRotatedArray(vector<int> arr , int n)
        {
            int count = 0;
            for(int i=0 ; i<n ; i++)
            {
                if(arr[i] >= arr[i+1]) 
                    count++;   
            }
            if(count == 0 || (count == 1 && arr[n-1] < arr[0])) return true;    // Important
            else return false;
        }
};

int main()
{
    solution obj;
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++)
    {
        cout << "Enter " << "element " << i+1 << ": ";
        cin >> arr[i];
    }
    
    bool IsSorted = obj.CheckSortedRotatedArray(arr , n);
   
    if(IsSorted) cout << "The array is sorted and rotated! in ascending order" << endl;
    else cout << "The array is not sorted!" << endl;
    return 0;
}