class Solution {
public:
    int solve(int index1,int index2,string s1,string s2,vector<vector<int>> &dp)
    {
        if(index1<0)return index2+1;
        if(index2<0)return index1+1;
        
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        
        if(s1[index1]==s2[index2])return dp[index1][index2]=0+solve(index1-1,index2-1,s1,s2,dp);
        
        return dp[index1][index2]=1+min({solve(index1-1,index2,s1,s2,dp),solve(index1-1,index2-1,s1,s2,dp), solve(index1,index2-1,s1,s2,dp)});
    }
    
    int minDistance(string word1, string word2) {
        
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        return solve(n-1,m-1,word1,word2,dp);
    }
};