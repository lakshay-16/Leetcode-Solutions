class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
        sum+=nums[i];
          
            if(sum%k==0&&i>=1)
                return true;
            
            if(m.find(sum%k)!=m.end()&&i-m[sum%k]>=2)
                return true;
            
            if(m.find(sum%k)==m.end())
                m[sum%k]=i;
        }
        
        return false;
    }
};