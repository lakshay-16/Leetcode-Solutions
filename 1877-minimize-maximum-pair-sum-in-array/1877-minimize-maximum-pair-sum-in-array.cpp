class Solution {
public:
    int minPairSum(vector<int>& nums) {
     
        int n=nums.size();
        vector<int> g;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n/2;i++)
        {
            int sum=nums[i]+nums[n-i-1];
            g.push_back(sum);
        }
        
        int ans=INT_MIN;
        for(int i=0;i<g.size();i++)
            ans=max(ans,g[i]);
        
        return ans;
    }
};