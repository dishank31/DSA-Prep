#include<iostream>
#include<vector>

using namespace std;

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
    
    int count = 0 , Maxcount = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] != 1)
        {
            Maxcount = count;
            count = 0;
        } 
        else count++;

        if(Maxcount < count) Maxcount = count;
    }
    cout << Maxcount << endl;

    return 0;
}