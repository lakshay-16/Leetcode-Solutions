class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       
      int sum=0;
        int sum1=0;
        int sum2=0;
        int ans1=INT_MIN;
        int ans2=INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            sum1+=nums[i];
            ans1=max(ans1,sum1);
            
            if(sum1<0)
                sum1=0;
            
            sum2+=nums[i];
            ans2=min(ans2,sum2);
            
            if(sum2>0)
                sum2=0;
        }
        
        
        if(sum==ans2)
            return ans1;
        
        return max(ans1,sum-ans2);
    }
};