class Solution {
public:
    int solve(string &a,string &b,int i1,int i2,vector<vector<int>> &dp)
    {
        if(i1<0||i2<0)
            return 0;
        
        if(dp[i1][i2]!=-1)
            return dp[i1][i2];
        
        
        if(a[i1]==b[i2])
           return dp[i1][i2]=1+solve(a,b,i1-1,i2-1,dp);
        
        
        return dp[i1][i2]=0+max(solve(a,b,i1-1,i2,dp),solve(a,b,i1,i2-1,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        
        int n=s.length();
        string g=s;
        reverse(g.begin(),g.end());
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        int ans=solve(s,g,n-1,n-1,dp);
        
        return ans;
    }
};