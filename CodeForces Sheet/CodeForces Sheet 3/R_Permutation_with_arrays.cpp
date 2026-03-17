#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i=0 ; i<N ; i++) cin >> A[i];

    vector<int> B(N);
    for(int j=0 ; j<N ; j++) cin >> B[j];

    unordered_map<int, int> mpp1;
    for(auto it : A) mpp1[it]++;

    unordered_map<int, int> mpp2;
    for(auto it : B) mpp2[it]++;

    if(mpp1 == mpp2) cout << "yes";
    else cout << "no";
}