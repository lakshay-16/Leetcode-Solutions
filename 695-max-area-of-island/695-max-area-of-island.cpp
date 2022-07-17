class Solution {
public:
    void solve(int i,int j,vector<vector<int>> &grid,int &count)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size())
            return;
        
        if(grid[i][j]!=1)
            return;
        
        grid[i][j]=0;
        count++;
        
        solve(i-1,j,grid,count);
        solve(i+1,j,grid,count);
        solve(i,j-1,grid,count);
        solve(i,j+1,grid,count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=0;
                    solve(i,j,grid,count);
                    ans=max(ans,count);
                }
            }
        }
        
        return ans;
    }
};