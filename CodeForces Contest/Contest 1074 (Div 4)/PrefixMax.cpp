#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> arr, int n)
{
    int largest = arr[0];
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] > largest) largest = arr[i];
    }
    return largest * n;
}

int main()
{
    int t;
    cout << "Number of test cases: " << endl;
    cin >> t;
    for(int i=0 ; i<t ; i++)
    {
        int n;
        cout << "Enter size of array : " << endl;
        cin >> n;
        vector<int> arr(n);
        for(int j=0 ; j<n ; j++)
        {
            cin >> arr[j];
        }
        int val = solution(arr,n);
        cout << "Value of array : " << val << endl;
    }
    return 0;
}