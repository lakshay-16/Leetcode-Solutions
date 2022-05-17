class Solution {
public:
    int solve(int i,int j,int r,int c,vector<vector<int>> &dp)
    {
        if(i<0||i>=r||j<0||j>=c)
            return 0;
        
        if(i==r-1&&j==c-1)
            return 1;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int left=solve(i+1,j,r,c,dp);
        int right=solve(i,j+1,r,c,dp);
        
        return dp[i][j]=left+right;
    }
    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solve(0,0,m,n,dp);
        
    }
};