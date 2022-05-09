class Solution {
public:
    int solve(int index1,int index2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(index1<0||index2<0)
            return 0;
        
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(s1[index1]==s2[index2])
            return dp[index1][index2]=1+solve(index1-1,index2-1,s1,s2,dp);
        
         return dp[index1][index2]=0+max(solve(index1-1,index2,s1,s2,dp),solve(index1,index2-1,s1,s2,dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return solve(n-1,m-1,text1,text2,dp);
    }
};