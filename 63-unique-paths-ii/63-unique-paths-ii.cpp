class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp)
    {
        if(i<0||i>=m.size()||j<0||j>=m[0].size())
        return 0;
        
          if(m[i][j]==1)
            return 0;
        
        if(i==m.size()-1&&j==m[0].size()-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left=solve(i+1,j,m,dp);
        int right=solve(i,j+1,m,dp);
        
        return dp[i][j]=left+right;
      
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int r=obstacleGrid.size();
        int c=obstacleGrid[0].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));
        
        return solve(0,0,obstacleGrid,dp);
    }
};