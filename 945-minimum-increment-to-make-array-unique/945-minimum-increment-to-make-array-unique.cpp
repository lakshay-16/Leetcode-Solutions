class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        
      int count=0;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            if(prev>=nums[i])
            {
                prev++;
                count+=prev-nums[i];
            }
            
            else
                prev=nums[i];
        }
        
        return count;
    }
};