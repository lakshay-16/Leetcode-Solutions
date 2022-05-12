class Solution {
public:
    bool solve(int index,int sum,vector<int> &nums,vector<vector<int>> &dp)
    {
        if(sum==0)
            return true;
        
        if(index==0)
            return (nums[0]==sum);
        
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        
        int nottake=solve(index-1,sum,nums,dp);
        int take=false;
        if(nums[index]<=sum)
            take=solve(index-1,sum-nums[index],nums,dp);
        
        return dp[index][sum]=(take||nottake);
    }
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n=nums.size();
        for(auto x:nums)
            sum+=x;
        
        if(sum%2!=0)
            return false;
        
        int dpsum=sum/2;
        vector<vector<int>> dp(n,vector<int> (dpsum+1,-1));
        
        return solve(n-1,dpsum,nums,dp);
    }
};