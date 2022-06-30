class Solution {
public:
    int houserobber(vector<int> &nums)
    {
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
          int n=nums.size();
        vector<int> dp(n);
           
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+nums[0];
        
        for(int i=3;i<n;i++)
        {
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        
        
        int ans=max(dp[n-2],dp[n-1]);
        
        return ans;
    }
    
    
    int rob(vector<int>& nums) {
        
           if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[1],nums[0]);
        
        vector<int> v1(nums.begin(), nums.end()-1);
        vector<int> v2(nums.begin()+1, nums.end());
        
        return max(houserobber(v1),houserobber(v2));
    }
};