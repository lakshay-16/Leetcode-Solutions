class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        if(nums.size()==1)
            return 1;
        
      map<int,int> m;
        vector<int> g;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto x:m)
            g.push_back(x.first);
        
        int prev=g[0];
        int count=1;
        int ans=INT_MIN;
        
        
        for(int i=1;i<g.size();i++)
        {
            if(g[i]-prev==1)
            {
                count++;
                prev=g[i];
            }
            
            else
            {
                count=1;
                prev=g[i];
            }
            
            ans=max(ans,count);
        }
        
        ans=max(ans,count);
        
        return ans;
    }
};