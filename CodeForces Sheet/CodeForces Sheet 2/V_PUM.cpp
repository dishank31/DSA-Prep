#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int count = 1;

    for(int i=0 ; i<N ; i++)
    {
        for(int j=0 ; j<4 ; j++)
        {
            if(count % 4 == 0)
            {
                cout << "PUM" << endl;
                count++;
            }
            else 
            {
                cout << count << " ";
                count++;
            }
        }
    }
    return 0;
}