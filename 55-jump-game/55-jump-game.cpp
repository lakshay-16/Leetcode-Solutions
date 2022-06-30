class Solution {
public:
    bool canJump(vector<int>& nums) {
       
           if(nums.size()==1)
            return true;
        
     
        
        int maxreach=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            maxreach=max(maxreach,i+nums[i]);
            
             if(maxreach==i)
            return false;
            
            if(maxreach>=nums.size()-1)
            return true;
        }
    
        return false;
       
    }
};