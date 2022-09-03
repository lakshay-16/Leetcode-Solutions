class Solution {
public:
       int mod=1e9+7;
    
    int solve(int i,int j,vector<vector<int>> &grid,int prev,vector<vector<int>> &dp)
    {
        if(i<0|j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]<=prev)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=1+max({solve(i+1,j,grid,grid[i][j],dp),solve(i-1,j,grid,grid[i][j],dp),solve(i,j-1,grid,grid[i][j],dp),solve(i,j+1,grid,grid[i][j],dp)});
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans,solve(i,j,matrix,-1,dp));
            }
        }
        
        return ans;
    }
};