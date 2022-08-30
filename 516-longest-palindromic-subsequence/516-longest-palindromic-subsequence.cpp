class Solution {
public:
    int solve(string &s1,string &s2,int index1,int index2,vector<vector<int>> &dp)
    {
        if(index1<0||index2<0)
            return 0;
        
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(s1[index1]==s2[index2])return dp[index1][index2]=1+solve(s1,s2,index1-1,index2-1,dp);
        
        return dp[index1][index2]=max(solve(s1,s2,index1-1,index2,dp),solve(s1,s2,index1,index2-1,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        
    string g=s;
        reverse(g.begin(),g.end());
        int n=s.length();
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        return solve(s,g,n-1,n-1,dp);
    }
};