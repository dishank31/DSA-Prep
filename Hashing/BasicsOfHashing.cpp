#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];   
    for(int i=0 ; i<n ; i++) cin >> arr[i];

    int hash[1000000] = {0};
    for(int i=0 ; i<n ; i++)
    {
        hash[arr[i]] += 1;
    }


    int k;
    cin >> k;
    while(k--)
    {
        int num;
        cin >> num;
        cout << hash[num] << endl;
    }
    return 0;
}