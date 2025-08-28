#include<bits/stdc++.h>

using namespace std;

void Subsequence(vector<int> &ds, int ind , int arr[], int n)
{
    if(ind == n)
    {
        for(auto it : ds) cout << it << "";
        if(ds.size() == 0) cout << "{}";
        cout << endl;
        return;
    }

    Subsequence(ds, ind+1, arr, n);

    ds.push_back(arr[ind]);
    Subsequence(ds, ind+1, arr, n);
    ds.pop_back();
    
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter values : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    vector<int> ds = {};
    Subsequence(ds, 0, arr, n); 
    return 0;
}