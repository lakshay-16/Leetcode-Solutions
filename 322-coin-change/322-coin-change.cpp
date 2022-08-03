class Solution {
public:
    int solve(int index,int val,vector<int> &g,vector<vector<int>> &dp)
    {
       if(index==0)
       {
           if(val%g[0]==0)return val/g[0];
           
           return 1e9;
       }
        
        if(dp[index][val]!=-1)
            return dp[index][val];
        
        int nottake=0+solve(index-1,val,g,dp);
        int take=1e9;
        if(val>=g[index])
            take=1+solve(index,val-g[index],g,dp);
        
        return dp[index][val]=min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        int ans=solve(n-1,amount,coins,dp);
        
        return (ans==1e9)?-1:ans;
    }
};