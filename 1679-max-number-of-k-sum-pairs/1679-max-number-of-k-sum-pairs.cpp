class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.size()==0)
                break;
            
            int x=k-nums[i];
            
            if(x==nums[i])
            {
            count+=m[x]/2;
                m.erase(x);
            }
            
            if(m.find(x)!=m.end())
            {
                count+=min(m[x],m[nums[i]]);
                m.erase(x);
                m.erase(nums[i]);
            }
        
        }
        
        return count;
    }
};