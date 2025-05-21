class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int color, int newcolor)
    {
        int m = image.size();
        int n = image[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != color)
        
            return;
        
        image[i][j] = newcolor;
        dfs(i + 1, j, image, color, newcolor);
        dfs(i - 1, j, image, color, newcolor);
        dfs(i, j + 1, image, color, newcolor);
        dfs(i, j - 1, image, color, newcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(oldcolor != color)
        {
            dfs(sr, sc, image, oldcolor, color);
        }
        return image;
    }
};