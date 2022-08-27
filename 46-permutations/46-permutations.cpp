class Solution {
public:
    void solve(string s,vector<vector<int>> &ans)
    {
        vector<int> g;
        for(auto x:s)
            g.push_back(x-'0');
            
        ans.push_back(g);
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size()<2)
            return {nums};
        
        string s="";
        for(auto x:nums)
            s+=x+'0';
        
        vector<vector<int>> ans;
        
        string g=s;
        next_permutation(s.begin(),s.end());
        solve(s,ans);
        
        while(s!=g)
        {
             next_permutation(s.begin(),s.end());
        solve(s,ans);
        }
        
        return ans;
    }
};