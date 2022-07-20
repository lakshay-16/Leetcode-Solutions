class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s=="")
            return true;
        
        if(t=="")
            return false;
        
        int pos=1;
        int i=t.find(s[0]);
        if(i==-1)
            return false;
        
        while(pos<s.length())
        {
            i=t.find(s[pos],i+1);
            if(i==-1)
                return false;
            
            pos++;
        }
        
        return true;
    }
};