class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &m,vector<vector<int>> &dp)
    {
        if(i<0||i>=m.size()||j<0||j>=m[0].size())
            return 1e9;
        
        if(i==m.size()-1&&j==m[0].size()-1)
            return m[i][j];
        
        if(dp[i][j]!=INT_MAX)
            return dp[i][j];
        
        int a=m[i][j]+solve(i+1,j,m,dp);
        int b=m[i][j]+solve(i,j+1,m,dp);
        
        return dp[i][j]=min(a,b);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int> (c,INT_MAX));
        
        
        return solve(0,0,grid,dp);
    }
};