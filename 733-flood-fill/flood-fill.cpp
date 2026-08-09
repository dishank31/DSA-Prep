class Solution {
public:
    void recur(vector<vector<int>>& image, int color, int m, int n, int i, int j, int pixel)
    {
        // Invalid Position
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        
        if(image[i][j] != pixel)
            return;

        image[i][j] = color;

        recur(image, color, m, n, i+1, j, pixel);
        recur(image, color, m, n, i-1, j, pixel);
        recur(image, color, m, n, i, j+1, pixel);
        recur(image, color, m, n, i, j-1, pixel);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int pixel = image[sr][sc];

        if(pixel == color) return image;
        
        recur(image, color, m, n, sr, sc, pixel);

        return image;
    }
};