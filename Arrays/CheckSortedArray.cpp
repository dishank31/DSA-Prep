#include<iostream>
#include<vector>
#include<array>

using namespace std;

class solution
{
    public:
        bool CheckSortedArray(vector<int> arr , int n)
        {
            for(int i=0 ; i<n ; i++)
            {
                if(arr[i+1] >= arr[i]) 
                {}
                else return false;    
            }
            return true;
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
    
    bool IsSorted = obj.CheckSortedArray(arr , n);
   
    if(IsSorted) cout << "The array is sorted! in ascending order" << endl;
    else cout << "The array is not sorted!" << endl;
    return 0;
}