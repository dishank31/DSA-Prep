#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

map<pair<int,int>, vector<pair<int,int>>> graph;
set<vector<pair<int,int>>> uniqueCycles;
pair<int,int> house;

vector<pair<int,int>> Cycle(vector<pair<int,int>> cycle) 
{
    int n = cycle.size();
    vector<pair<int,int>> minCycle = cycle;
    
    for(int start = 0; start < n; start++) {
        vector<pair<int,int>> rotated;
        for(int i = 0; i < n; i++) {
            rotated.push_back(cycle[(start + i) % n]);
        }
        if(rotated < minCycle) {
            minCycle = rotated;
        }
    }
    
    reverse(cycle.begin(), cycle.end());
    for(int start = 0; start < n; start++) {
        vector<pair<int,int>> rotated;
        for(int i = 0; i < n; i++) {
            rotated.push_back(cycle[(start + i) % n]);
        }
        if(rotated < minCycle) {
            minCycle = rotated;
        }
    }
    
    return minCycle;
}

void depth_first_search(pair<int,int> current, vector<pair<int,int>>& path, set<pair<int,int>>& visited) 
{
    for(auto& neighbor : graph[current]) 
    {
        if(neighbor == house) 
        {
            if(path.size() >= 3)
            {
                vector<pair<int,int>> cycle = path;
                vector<pair<int,int>> normalized = Cycle(cycle);
                uniqueCycles.insert(normalized);
            }
            continue;
        }
        
        if(visited.count(neighbor)) 
        {
            continue;
        }
        
        visited.insert(neighbor);
        path.push_back(neighbor);
        
        depth_first_search(neighbor, path, visited);
        
        path.pop_back();
        visited.erase(neighbor);
    }
}

int main() 
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) 
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        pair<int,int> p1 = {x1, y1};
        pair<int,int> p2 = {x2, y2};
        
        graph[p1].push_back(p2);
        graph[p2].push_back(p1);
    }
    
    int x, y;
    cin >> x >> y;
    house = {x, y};
   
    vector<pair<int,int>> path;
    set<pair<int,int>> visited;
    
    path.push_back(house);
    visited.insert(house);
    
    depth_first_search(house, path, visited);
    
    cout << uniqueCycles.size() << endl;
    
    return 0;
}