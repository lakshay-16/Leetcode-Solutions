class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(int i=1;i<=n;i++)
            tsum+=i;
        
        int sum=0;
        for(auto x:nums)
            sum+=x;
            
        return tsum-sum;
    }
};