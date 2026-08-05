class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> nextboard = board;

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int count = 0;
                if(j-1 >= 0)
                {
                    if(i-1 >= 0 && nextboard[i-1][j-1] == 1) count++;
                    if(i+1 < m && nextboard[i+1][j-1] == 1) count++;
                    if(nextboard[i][j-1]) count++;
                }

                if(j+1 < n)
                {
                    if(i-1 >= 0 && nextboard[i-1][j+1] == 1) count++;
                    if(i+1 < m && nextboard[i+1][j+1] == 1) count++;
                    if(nextboard[i][j+1]) count++;
                }

                if(i-1 >= 0 && nextboard[i-1][j] == 1) count++;
                if(i+1 < m && nextboard[i+1][j] == 1) count++;

                if(nextboard[i][j] == 0 && count == 3) board[i][j] = 1;
                if(nextboard[i][j] == 1 && (count != 2 && count != 3)) board[i][j] = 0;
            }
        }
    }
};