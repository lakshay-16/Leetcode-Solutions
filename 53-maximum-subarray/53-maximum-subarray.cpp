class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      
        int sum=0;
        int maxsum=0;
        int maxelement=INT_MIN;
        bool flag=true;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
                flag=false;
            
            sum+=nums[i];
            maxelement=max(maxelement,nums[i]);
                
            if(sum<0)
                sum=0;
            
            maxsum=max(maxsum,sum);
        }
      
        if(flag)
            return maxelement;
        
        return maxsum;
    }
};