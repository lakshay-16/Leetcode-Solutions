class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int left=j+1;
                int right=n-1;
                int nt=target-nums[i]-nums[j];
                
                while(left<right)
                {
                    int sum=nums[left]+nums[right];
                    
                 if(sum==nt)
                 {
                     s.insert({nums[i],nums[j],nums[left],nums[right]});
                         left++;
                     right--;
                 }
                    
                    else if(sum<nt)
                    left++;
                    
                    else
                        right--;
                }
            }
        }
        
        for(auto x:s)
            ans.push_back(x);
        
        return ans;
    }
};