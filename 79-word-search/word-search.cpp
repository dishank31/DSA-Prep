class Solution {
public:
    bool check(int i, int j, int idx, vector<vector<char>>& board, string word, int m, int n)
    {
        // Invalid Position
        if(i<0 || i>=m || j<0 || j>=n)
            return false;
        
        // Wrong character
        if(board[i][j] != word[idx])
            return false;
        
        // Complete word match
        if(idx == word.size()-1)
            return true;
        
        char temp = board[i][j];
        board[i][j] = '#';       // Visited

        bool found = check(i+1, j, idx+1, board, word, m, n) || 
                     check(i-1, j, idx+1, board, word, m, n) || 
                     check(i, j+1, idx+1, board, word, m, n) || 
                     check(i, j-1, idx+1, board, word, m, n);

        board[i][j] = temp; 

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int i=0 ; i<m ; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(board[i][j] == word[0])
                {
                    if(check(i, j, 0, board, word, m, n))
                        return true;
                }
            }
        }

        return false;
    }
};