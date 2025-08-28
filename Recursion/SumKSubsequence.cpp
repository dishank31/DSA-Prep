#include<iostream>
#include<vector>

using namespace std;

// void Subsequence(vector<int> &ds, vector<int> arr, int ind, int sum, int n, int s)
// {
//     if(ind == n)
//     {
//         if(s == sum)
//         {
//             for(auto it : ds) cout << it << " ";
//             cout << endl;
//         }
//         return;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
    
//     Subsequence(ds, arr, ind+1, sum, n, s);         // Pick
    
//     s -= arr[ind];
//     ds.pop_back();
//     Subsequence(ds, arr, ind+1, sum, n, s);         // Not pick
// }

// bool PrintOneSubsequence(vector<int> &ds, vector<int> arr, int ind, int sum, int n, int s)
// {
//     if(ind == n)
//     {
//         if(s == sum)
//         {
//             for(auto it : ds) cout << it << " ";
//             return true;
//         }
//         return false;
//     }

//     ds.push_back(arr[ind]);
//     s += arr[ind];
//     if(PrintOneSubsequence(ds, arr, ind+1, sum, n, s) == true) return true;

//     s -= arr[ind];
//     ds.pop_back();
//     if(PrintOneSubsequence(ds, arr, ind+1, sum, n, s) == true) return true;

//     return false;
// }

int PrintCountOfSubsequence(vector<int> arr, int ind, int sum, int n, int s)
{
    if(ind == n)
    {
        if(s == sum)
        {
            return 1;
        }
        return 0;
    }

    s += arr[ind];
    int l = PrintCountOfSubsequence(arr, ind+1, sum, n, s);

    s -= arr[ind];
    int r = PrintCountOfSubsequence(arr, ind+1, sum, n, s);

    return (l+r);
}

int main()
{
    int n , sum = 0;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the values while giving space : ";
    for(int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the sum you want : ";
    cin >> sum;
    vector<int> ds;
    // Subsequence(ds, arr, 0, sum, n, 0);
    // PrintOneSubsequence(ds, arr, 0, sum, n, 0);
    cout << PrintCountOfSubsequence(arr, 0, sum, n, 0);
    return 0;
}