#include<iostream>
#include<vector>

using namespace std;

int SingleNumber(vector<int>& arr, int n)
{
    int res = 0;
    for(int i=0 ; i<n ; i++)
    {
        
    }
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter numbers while giving space : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    cout << SingleNumber(arr, n) << endl;
    return 0;
}