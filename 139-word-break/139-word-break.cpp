class Solution {
public:
    int dp[301];
    unordered_map<string,int> m;
    
    int solve(int index,string s)
    {
        if(index==s.length())
        return 1;
        
        if(dp[index]!=-1)
            return dp[index];
        
        string temp="";
        for(int i=index;i<s.size();i++)
        {
            temp+=s[i];
            if(m.find(temp)!=m.end())
            {
                if(solve(i+1,s))
                    return dp[index]=1;
            }
        }
        
        return dp[index]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
    
        memset(dp,-1,sizeof(dp));
        for(auto x:wordDict)
            m[x]++;
        
        return solve(0,s);
    }
};