class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
       vector<int> ans;
        if(k==1)
        {
            for(int i=1;i<nums.size()-1;i++)
                ans.push_back(i);
            
            return ans;
        }
        
        vector<bool> right(nums.size(),false);
        vector<bool> left(nums.size(),false);
       
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            count++;
            if(nums[i]>=nums[i-1])
            {
                if(count>=k)
                right[i]=true;
                
                continue;
            }
            else
            {
                count=1;
                right[i]=false;
            }
        }
        
        count=1;
        
         for(int i=nums.size()-2;i>=0;i--)
        {
            count++;
            if(nums[i]>=nums[i+1])
            {
                if(count>=k)
                left[i]=true;
                
                continue;
            }
            
            else
            {
                count=1;
                left[i]=false;
            }
        }
        
        
        for(int i=k;i<nums.size()-k;i++)
        {
            if(left[i-k]&&right[i+k])
                ans.push_back(i);
        }
        
        return ans;
    }
};