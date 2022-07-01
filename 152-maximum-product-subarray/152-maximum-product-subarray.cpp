class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int pro1=nums[0];
        int pro2=nums[0];
        
        int ans=nums[0];
        
        for(int i=1;i<nums.size();i++)
        {
            int temp=max({nums[i],nums[i]*pro1,nums[i]*pro2});
            pro2=min({nums[i],nums[i]*pro1,nums[i]*pro2});
            pro1=temp;
            ans=max(pro1,ans);
        }
        
        return ans;
    }
};