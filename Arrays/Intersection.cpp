#include<iostream>
#include<vector>

using namespace std;

// Optimal Approach
// TC: O(n1+n2) Worst Case All elements are different.
// SC: O(n1+n2) 
vector<int> Intersection(vector<int>& arr1, vector<int>& arr2, int n1, int n2)
{
    vector<int> res;
    int i=0 , j=0;
    
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j]) i++;
        else if(arr1[i] > arr2[j]) j++;
        else
        {
            res.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    
    return res;
}

int main()
{
    int n1;
    cout << "Enter size of first array : ";
    cin >> n1;
    vector<int> arr1(n1);
    cout << "Enter " << n1 << " intgers while giving space : ";
    for(int i=0 ; i<n1 ; i++)
    {
        cin >> arr1[i];
    }
    int n2;
    cout << "Enter size of second array : ";
    cin >> n2;
    vector<int> arr2(n2);
    cout << "Enter " << n2 << " intgers while giving space : ";
    for(int i=0 ; i<n2 ; i++)
    {
        cin >> arr2[i];
    }
    vector<int> Result = Intersection(arr1, arr2, n1, n2);
    for(auto it : Result)
    {
        cout << it << " ";
    }
    return 0;
}