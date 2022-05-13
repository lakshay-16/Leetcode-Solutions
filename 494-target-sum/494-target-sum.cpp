class Solution {
public: int total=0;
    int cal(vector<int> &nums,int target,int sum,int index,vector<vector<int>> &dp)
    {
        if(index==nums.size())
        {
            if(sum==target)
                return 1;
            
            else
return 0;
        }
        
        if(dp[index][sum+total]!=-1)
            return dp[index][sum+total];
        
        int add=cal(nums,target,sum+nums[index],index+1,dp);
        int min=cal(nums,target,sum-nums[index],index+1,dp);
        
        return dp[index][sum+total]=add+min;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
       
        int n=nums.size();
        for(auto x:nums)
            total+=x;
        
        vector<vector<int>> dp(n,vector<int> (total*2+1,-1));
        return cal(nums,target,0,0,dp);
    }
};