class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &g,vector<vector<int>> &dp)
    {
        if(i<0||i>=g.size()||j<0||j>=g[0].size())
            return 1e9;
        
        if(i==g.size()-1&&j==g[0].size()-1)
            return g[i][j];
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=g[i][j]+solve(i,j+1,g,dp);
        int forward=g[i][j]+solve(i+1,j,g,dp);
        
        return dp[i][j]=min(down,forward);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return solve(0,0,grid,dp);
    }
};