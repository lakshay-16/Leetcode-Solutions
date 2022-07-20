class Solution {
public:
    bool sub(string &s,string &g)
    {
        int pos=1;
        int i=g.find(s[0]);
        if(i==-1)
            return false;
        
        while(pos<s.length())
        {
            i=g.find(s[pos],i+1);
            if(i==-1)
                return false;
            
            pos++;
        }
        
        return true;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        
        int ans=0;
        for(auto x:words)
        {
            if(sub(x,s))
                ans++;
        }
      
        return ans;
    }
};