class Solution {
public:    
    int rob(vector<int>& nums) {
       
        if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+dp[0];
        int ans=max({dp[1],dp[0],dp[2]});
        
        for(int i=3;i<nums.size();i++)
        {
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
            ans=max(dp[i],ans);
        }
        
        return ans;
    }
};