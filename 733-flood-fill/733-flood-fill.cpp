class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &grid,int c,int sc)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return;
        
        if(grid[i][j]!=sc)
            return;
        
        if(grid[i][j]==c)
            return;
        
        grid[i][j]=c;
        
        dfs(i+1,j,grid,c,sc);
        dfs(i-1,j,grid,c,sc);
        dfs(i,j-1,grid,c,sc);
        dfs(i,j+1,grid,c,sc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        dfs(sr,sc,image,color,image[sr][sc]);
        return image;
    }
};