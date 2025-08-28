// Considering there are no negative integers in an array

#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include<limits.h>

using namespace std;

class solution
{
    public:
        int second_largest(vector<int> &arr , int n)
        {
            int largest = arr[0];
            for(int i=0 ; i<n ; i++)
            {
                if(arr[i] > largest)
                {
                    largest = arr[i];
                }
            }

            int sec_largest = INT_MIN;
            for(int j=0 ; j<n ; j++)
            {
                if(arr[j] != largest && arr[j] > sec_largest)
                {
                    sec_largest = arr[j];
                }
            }
            return sec_largest;
        }

        int optimal_approach(vector<int> &a , int n)
        {
            int largest = a[0];
            int sec_largest = INT_MIN;
            for(int i=0 ; i<n ; i++)
            {
                if(a[i] > largest)
                {
                    sec_largest = largest;
                    largest = a[i];
                }
                else if(a[i] < largest && a[i] > sec_largest)
                {
                    sec_largest = a[i];
                }
            }
            return sec_largest;
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

    int res = obj.optimal_approach(arr , n);
    cout << "The second largest element is : " << res << endl;
    return 0;
}