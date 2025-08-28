    // #include<iostream>
    // #include<set>
    // #include<vector>

    // using namespace std;

    // set<int> Union(vector<int>& arr1, vector<int>& arr2)
    // {
    //     set<int> s;
    //     for(int i=0 ; i<arr1.size() ; i++)
    //     {
    //         s.insert(arr1[i]);
    //     }
    //     for(int i=0 ; i<arr2.size() ; i++)
    //     {
    //         s.insert(arr2[i]);
    //     }
    //     return s;
    // }   

    // int main()
    // {
    //     int n1;
    //     cout << "Enter size of first array : ";
    //     cin >> n1;
    //     vector<int> arr1(n1);
    //     cout << "Enter " << n1 << " intgers while giving space : ";
    //     for(int i=0 ; i<n1 ; i++)
    //     {
    //         cin >> arr1[i];
    //     }
    //     int n2;
    //     cout << "Enter size of second array : ";
    //     cin >> n2;
    //     vector<int> arr2(n2);
    //     cout << "Enter " << n2 << " intgers while giving space : ";
    //     for(int i=0 ; i<n2 ; i++)
    //     {
    //         cin >> arr2[i];
    //     }
    //     set<int> s = Union(arr1, arr2);
    //     for(auto it : s)
    //     {
    //         cout << it << " ";
    //     }
    //     return 0;
    // }

    // SC = O(n1logn)+O(n2logn)+O(n1+n2)
    // TC = O(n1+n2) + O(n1+n2) 

// ____________________________________________________________________________________________________________________________

// Optimal Approach

#include<iostream>
#include<vector>

using namespace std;

vector<int> OptimalUnion(vector<int>& arr1, vector<int>& arr2, int n1, int n2)
{
    int i = 0;
    int j = 0;
    vector<int> Union;
    
    while(i<n1 && j<n2)
    {
        if(arr1[i] <= arr2[j])
        {
            if(Union.size() == 0 || Union.back() != arr1[i])
            {
                Union.emplace_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if(Union.size() == 0 || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i<n1)
    {
        if(Union.size() == 0 || Union.back() != arr1[i])
            {
                Union.emplace_back(arr1[i]);
            }
        i++;
    }
    while(j<n2)
    {
         if(Union.size() == 0 || Union.back() != arr2[j])
            {
                Union.push_back(arr2[j]);
            }
        j++;
    }

    return Union;
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
    vector<int> Union = OptimalUnion(arr1, arr2, n1, n2);
    for(auto it : Union)
    {
        cout << it << " ";
    }
    return 0;
}

// TC : O(n1 + n2) Traversing each element only once
// SC : O(n1 + n2) for only returning the result not using in our code