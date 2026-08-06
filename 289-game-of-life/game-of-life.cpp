class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                int count = 0;
                if(j-1 >= 0)
                {
                    if(i-1 >= 0 && (board[i-1][j-1] == 1 || board[i-1][j-1] == 3)) count++;
                    if(i+1 < m && (board[i+1][j-1] == 1 || board[i+1][j-1] == 3)) count++;
                    if(board[i][j-1] == 1|| board[i][j-1] == 3) count++;
                }

                if(j+1 < n)
                {
                    if(i-1 >= 0 && (board[i-1][j+1] == 1 || board[i-1][j+1] == 3)) count++;
                    if(i+1 < m && (board[i+1][j+1] == 1 || board[i+1][j+1] == 3)) count++;
                    if(board[i][j+1] == 1 || board[i][j+1] == 3) count++;
                }

                if(i-1 >= 0 && (board[i-1][j] == 1 || board[i-1][j] == 3)) count++;
                if(i+1 < m && (board[i+1][j] == 1 || board[i+1][j] == 3)) count++;

                if(board[i][j] == 0 && count == 3) board[i][j] = 2;
                if(board[i][j] == 1 && (count < 2 || count > 3)) board[i][j] = 3;
            }
        }

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};