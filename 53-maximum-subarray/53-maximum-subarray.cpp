class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum=0;
        int maxsum=INT_MIN;
        bool flag=true;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            
            if(nums[i]>=0)
                flag=false;
            
            if(sum<0)
                sum=0;
            
            maxsum=max(maxsum,sum);
        }
        
        if(flag)
        {
            sort(nums.begin(),nums.end());
                maxsum=nums[nums.size()-1];
        }
        
        return maxsum;
    }
};