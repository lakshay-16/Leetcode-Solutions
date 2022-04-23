class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int ans=0;
        int i=0;
        
        
        while(i<nums.size()-1)
        {
            int x=i-ans;
            if(x%2==0&&nums[i]==nums[i+1])
                ans++;
                
            i++;
        }
       
        if((nums.size()-ans)%2!=0)
            ans++;
        
        
        return ans;
    }
};