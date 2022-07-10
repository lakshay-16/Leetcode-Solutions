class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &g,vector<vector<int>> &dp)
    {
        
         if(i<0||i>=g.size()||j<0||j>=g[0].size())
            return 0;
        
          if(g[i][j]==1)
            return 0;
        
        if(i==g.size()-1&&j==g[0].size()-1)
            return 1;
        
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=solve(i,j+1,g,dp);
        int forward=solve(i+1,j,g,dp);
        
        return dp[i][j]=down+forward;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return solve(0,0,obstacleGrid,dp);
        
    }
};