class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long count=0;
        long long gp=0;
        
        for(int i=0;i<nums.size();i++)
            count+=(nums.size()-i-1);
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int dif=nums[i]-i;
            
            if(m[dif]>0)
                gp+=m[dif];
            
            m[dif]++;
        }
        
        return count-gp;
    }
};