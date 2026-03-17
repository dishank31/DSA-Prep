#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

int if_valid(char n, char s)
{
    map<pair<char,char>, int> mpp;
    
    mpp[{'1','S'}] = 1;
    mpp[{'1','L'}] = 1;
    mpp[{'1','R'}] = 1;
    mpp[{'1','U'}] = 1;
    mpp[{'1','D'}] = 1;
    
    mpp[{'2','S'}] = 2;
    mpp[{'2','L'}] = 5;
    mpp[{'2','R'}] = 5;
    mpp[{'2','U'}] = 5;
    mpp[{'2','D'}] = 5;
    
    mpp[{'9','S'}] = 9;
    mpp[{'9','L'}] = -1;
    mpp[{'9','R'}] = -1;
    mpp[{'9','U'}] = -1;
    mpp[{'9','D'}] = -1;
    
    mpp[{'3','S'}] = 3;
    mpp[{'3','L'}] = -1;
    mpp[{'3','R'}] = -1;
    mpp[{'3','U'}] = 3;
    mpp[{'3','D'}] = 3;
    
    mpp[{'4','S'}] = 4;
    mpp[{'4','L'}] = -1;
    mpp[{'4','R'}] = -1;
    mpp[{'4','U'}] = -1;
    mpp[{'4','D'}] = -1;
    
    mpp[{'5','S'}] = 5;
    mpp[{'5','L'}] = 2;
    mpp[{'5','R'}] = 2;
    mpp[{'5','U'}] = 2;
    mpp[{'5','D'}] = 2;
    
    mpp[{'6','S'}] = 6;
    mpp[{'6','L'}] = -1;
    mpp[{'6','R'}] = -1;
    mpp[{'6','U'}] = -1;
    mpp[{'6','D'}] = -1;
    
    mpp[{'7','S'}] = 7;
    mpp[{'7','L'}] = -1;
    mpp[{'7','R'}] = -1;
    mpp[{'7','U'}] = -1;
    mpp[{'7','D'}] = -1;
    
    mpp[{'8','S'}] = 8;
    mpp[{'8','L'}] = 8;
    mpp[{'8','R'}] = 8;
    mpp[{'8','U'}] = 8;
    mpp[{'8','D'}] = 8;
    
    mpp[{'0','S'}] = 0;
    mpp[{'0','L'}] = 0;
    mpp[{'0','R'}] = 0;
    mpp[{'0','U'}] = 0;
    mpp[{'0','D'}] = 0;
    
    if(mpp.find({n,s}) != mpp.end()) return mpp[{n,s}];
    else return -1;
}
    
int main()
{
    string str, s;
    cin >> str >> s;

    vector<int> v;

    for (size_t i = 0; i < str.size(); i++) {
        int val = if_valid(str[i], s[i]);
        if (val == -1) continue;
        else v.push_back(val);
    }
    
    if(v.empty()) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());
    
    bool zero = true;
    for(int j : v) {
        if(j != 0) {
            zero = false;
            break;
        }
    }
    
    if(zero) {
        cout << 0;
        return 0;
    }
    
    // Swapping first position with a non-zero integer
    for(size_t i=0; i<v.size(); i++)
    {
        if(v[i] != 0)
        {
            swap(v[0], v[i]);
            break;
        }
    }
    
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i];
    return 0;
}