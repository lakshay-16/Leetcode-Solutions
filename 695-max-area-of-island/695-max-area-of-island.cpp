class Solution {
public:
      void dfs(int i,int j,int &count,vector<vector<int>> &grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
            return;
        
        if(grid[i][j]!=1)
            return;
            
        count++;
        grid[i][j]=0;
        dfs(i+1,j,count,grid);
        dfs(i-1,j,count,grid);
        dfs(i,j+1,count,grid);
        dfs(i,j-1,count,grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
           int ans=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                  int count=0;
                    dfs(i,j,count,grid);
                    ans=max(ans,count);
                }
            }
        }
        
        return (ans==INT_MIN)?0:ans;
    }
};