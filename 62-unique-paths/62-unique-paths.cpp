class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &dp,int n,int m)
    {
        if(i==n-1&&j==m-1)
            return 1;
        
        if(i<0||i>=n||j<0||j>=m)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=solve(i,j+1,dp,n,m);
        int forward=solve(i+1,j,dp,n,m);
        
        
        return dp[i][j]=down+forward;
    }
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return solve(0,0,dp,m,n);
    }
};