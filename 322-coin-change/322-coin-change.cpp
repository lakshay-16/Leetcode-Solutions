class Solution {
public:
  int solve(int index,int t,vector<int> &nums,vector<vector<int>> &dp)
  {
      if(index==0)
      {
          if(t%nums[0]==0) return t/nums[0];
          
          return 1e9;
      }
  
      if(dp[index][t]!=-1) return dp[index][t];
      
  int nottake=0+solve(index-1,t,nums,dp);
      int take=INT_MAX;
      if(t>=nums[index])
      {
          take=1+solve(index,t-nums[index],nums,dp);
      }
  
  
      return dp[index][t]=min(take,nottake);
  }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
      int ans=solve(n-1,amount,coins,dp);
        
        return (ans==1e9)?-1:ans;
    }
};