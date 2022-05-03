class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      vector<int> g=nums;  
      sort(g.begin(),g.end());
        int n=nums.size();
        
        int i=0;
        int j=nums.size()-1;
        
        while(i<n&&nums[i]==g[i])
            i++;
        
        while(j>i&&nums[j]==g[j])
            j--;
        
        
        return j-i+1;
    }
};