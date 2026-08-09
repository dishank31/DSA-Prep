class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int m, int n)
    {
        // Invalid Position
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        
        // Already visited or water
        if(grid[i][j] == '0')
            return;
        
        grid[i][j] = '0';       // Already Visited
        
        dfs(i+1, j, grid, m , n);
        dfs(i-1, j, grid, m , n);
        dfs(i, j-1, grid, m , n);
        dfs(i, j+1, grid, m , n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        int cnt = 0;

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    dfs(i, j, grid, m, n);
                }
            }
        }

        return cnt;
    }
};