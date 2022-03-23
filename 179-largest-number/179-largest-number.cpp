class Solution {
public:
    static bool comp(string &a,string &b)
    {
        string x=a+b;
        string y=b+a;
        
        return x>y;
    }
    
    string largestNumber(vector<int>& nums) {
     
     vector<string> g;
        for(int i=0;i<nums.size();i++)
        {
            string x=to_string(nums[i]);
            g.push_back(x);
        }
        
        sort(g.begin(),g.end(),comp);
     
        string ans="";
        for(int i=0;i<g.size();i++)
            ans+=g[i];
        
        if(ans[0]=='0')
            return "0";
        
        
    return ans;
    }
    
};