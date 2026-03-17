#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<string>
#include<algorithm>

using namespace std;

int if_valid(int n, string s)
{
	map<pair<char,char>, int> mpp;
    
    mpp[{'1','S'}] = 1;			// for 1
    mpp[{'1','L'}] = 1;
    mpp[{'1','R'}] = 1;
    mpp[{'1','U'}] = 1;
    mpp[{'1','D'}] = 1;
    
    mpp[{'2','S'}] = 2;			// for 2
    mpp[{'2','L'}] = 5;
    mpp[{'2','R'}] = 5;
    mpp[{'2','U'}] = 5;
    mpp[{'2','D'}] = 5;
    
    mpp[{'9','S'}] = 9;			// for 9
    mpp[{'9','L'}] = -1;
    mpp[{'9','R'}] = -1;
    mpp[{'9','U'}] = -1;
    mpp[{'9','D'}] = -1;
    
    mpp[{'3','S'}] = 3;			// for 3
    mpp[{'3','L'}] = -1;
    mpp[{'3','R'}] = -1;
    mpp[{'3','U'}] = 3;
    mpp[{'3','D'}] = 3;
    
    mpp[{'4','S'}] = 4;			// for 4
    mpp[{'4','L'}] = -1;
    mpp[{'4','R'}] = -1;
    mpp[{'4','U'}] = -1;
    mpp[{'4','D'}] = -1;
    
    mpp[{'5','S'}] = 5;			// for 5
    mpp[{'5','L'}] = 2;
    mpp[{'5','R'}] = 2;
    mpp[{'5','U'}] = 2;
    mpp[{'5','D'}] = 2;
    
    mpp[{'6','S'}] = 6;			// for 6
    mpp[{'6','L'}] = -1;
    mpp[{'6','R'}] = -1;
    mpp[{'6','U'}] = -1;
    mpp[{'6','D'}] = -1;
    
    mpp[{'7','S'}] = 7;			// for 7
    mpp[{'7','L'}] = -1;
    mpp[{'7','R'}] = -1;
    mpp[{'7','U'}] = -1;
    mpp[{'7','D'}] = -1;
    
    mpp[{'8','S'}] = 8;			// for 8
    mpp[{'8','L'}] = 8;
    mpp[{'8','R'}] = 8;
    mpp[{'8','U'}] = 8;
    mpp[{'8','D'}] = 8;
    
    mpp[{'0','S'}] = 0;			// for 0
    mpp[{'0','L'}] = 0;
    mpp[{'0','R'}] = 0;
    mpp[{'0','U'}] = 0;
    mpp[{'0','D'}] = 0;
    
    if(mpp.find({n,s}) != mpp.end()) return mpp[{n,s}];
    else return -1;
}
	
int main()
{
    int n;
    string s;
    cin >> n >> s;

    string str = to_string(n);
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        int val = if_valid(str[i], s[i]);
        if (val == -1) continue;
        else v.push_back(val);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i];
    return 0;
}