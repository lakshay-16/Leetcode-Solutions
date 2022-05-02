class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> odd;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)
                odd.push_back(nums[i]);
            
            else
                ans.push_back(nums[i]);
        }
        
        for(int i=0;i<odd.size();i++)
            ans.push_back(odd[i]);
    
    return ans;
    }
};