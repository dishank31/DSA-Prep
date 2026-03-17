#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<climits>
using namespace std;

int n;
vector<vector<char>> grid;
pair<int,int> source, destination;

void Input_processing(vector<string>& lines) 
{
    grid.assign(n, vector<char>(n, ' '));
    int row = 0;
    
    for(int i = 0; i < n; i++) 
    {
        string line = lines[i];
        int col = 0;
        size_t idx = 0;
        
        while(idx < line.length() && col < n) 
        {
            string num_str = "";
            while(idx < line.length() && isdigit(line[idx])) 
            {
                num_str += line[idx];
                idx++;
            }
            
            if(idx < line.length()) 
            {
                char brick = line[idx];
                int count = stoi(num_str);
                
                for(int k = 0; k < count && col < n; k++) 
                {
                    grid[row][col] = brick;
                    if(brick == 'S') source = make_pair(row, col);
                    if(brick == 'D') destination = make_pair(row, col);
                    col++;
                }
                idx++;
            }
        }
        row++;
    }
}

int findMinGreenBricks() 
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    auto cmp = [](const pair<pair<int,int>, int>& a, const pair<pair<int,int>, int>& b) {
        return a.second > b.second;
    };
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, decltype(cmp)> pq(cmp);
    
    dist[source.first][source.second] = 0;
    pq.push(make_pair(source, 0));
    
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    while(!pq.empty()) 
    {
        auto current = pq.top();
        pq.pop();
        
        int x = current.first.first;
        int y = current.first.second;
        int currentDist = current.second;
        
        if(x == destination.first && y == destination.second) return currentDist;
        if(currentDist > dist[x][y]) continue;
        
        for(int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'R') 
            {
                int newDist = currentDist + (grid[nx][ny] == 'G' ? 1 : 0);
                if(newDist < dist[nx][ny]) 
                {
                    dist[nx][ny] = newDist;
                    pq.push(make_pair(make_pair(nx, ny), newDist));
                }
            }
        }
    }
    
    return -1;
}

int main() 
{
    cin >> n;
    cin.ignore();
    
    vector<string> lines(n);
    for(int i = 0; i < n; i++) 
    {
        getline(cin, lines[i]);
    }
    
    Input_processing(lines);
    int result = findMinGreenBricks();
    cout << result;
    
    return 0;
}