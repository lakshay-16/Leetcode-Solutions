class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
       if(nums.size()<3)
           return 0;
        
        int n=nums.size();
        int ans=0;
        int dif;
        
        for(int i=0;i<n-2;i++)
        {
            dif=nums[i+1]-nums[i];
            
            for(int j=i+2;j<n;j++)
            {
                if(nums[j]-nums[j-1]==dif)
                    ans++;
                
                else
                    break;
            }
        }
        
        return ans;
    }
};