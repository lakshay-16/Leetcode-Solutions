class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> g;
        int sum=0;
        for(auto x:nums)
        {
            sum+=x;
            g.push_back(sum);
        }
        
        return g;
    }
};