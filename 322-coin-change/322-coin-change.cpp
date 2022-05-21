class Solution {
public:
    int solve(int amount,int index,vector<int> &count,vector<vector<int>> &dp)
    {
        if(index==0)
        {
            if(amount%count[0]==0) return amount/count[0];
                
            return 1e9;
        }
        
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        
        int nottake=0+solve(amount,index-1,count,dp);
        int take=INT_MAX;
        if(amount>=count[index])
            take=1+solve(amount-count[index],index,count,dp);
        
        return dp[index][amount]=min(take,nottake);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        int ans=solve(amount,n-1,coins,dp);
        
        return (ans==1e9)?-1:ans;
    }
};