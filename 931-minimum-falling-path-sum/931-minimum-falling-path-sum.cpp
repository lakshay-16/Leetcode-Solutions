class Solution {
public:
    int solve(int index,int level,vector<vector<int>> &dp,vector<vector<int>> &g)
    {
      if(index<0||index>=g.size())
          return 1e9;
        
        if(dp[level][index]!=-1)
            return dp[level][index];
        
        if(level==0)
            return g[level][index];
        
        int prev=g[level][index]+solve(index-1,level-1,dp,g);
        int cur=g[level][index]+solve(index,level-1,dp,g);
        int next=g[level][index]+solve(index+1,level-1,dp,g);
        
        return dp[level][index]=min({prev,cur,next});
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
     
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        for(int i=0;i<n;i++)
            ans=min(ans,solve(i,n-1,dp,matrix));
        
        
        
        return ans;
    }
};