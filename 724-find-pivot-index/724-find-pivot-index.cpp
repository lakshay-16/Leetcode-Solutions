class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        
        int ans=-1;
        int n=nums.size();
        
        vector<int> prefix;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            prefix.push_back(sum);
        }
        
        
        for(int i=0;i<n;i++)
        {
            int left,right;
            if(i==0)
            left=0;
            
            else
                left=prefix[i-1];
          
            if(i==n-1)
                right=0;
            
            else
                right=prefix[n-1]-prefix[i];
                
            
            if(left==right)
            {
                ans=i;
             break;   
            }
        }
        
        
        return ans;
    }
};