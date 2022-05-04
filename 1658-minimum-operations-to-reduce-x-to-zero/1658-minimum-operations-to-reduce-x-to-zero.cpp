class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
     int len=INT_MIN;
        int sum=0;
        int tsum=0;
        for(auto y:nums)
            tsum+=y;
        
        tsum-=x;
        int j=0;
        int i;
        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>tsum&&i>=j)
            {
              sum-=nums[j];
                j++;
            }
            
            if(sum==tsum)
                len=max(len,i-j+1);
            
        }
        
        
        return (len==INT_MIN)?-1:nums.size()-len;
    }
};