class Solution {
public:
    string convert(string s)
    {
        string p="";
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#'&&!st.empty())
                st.pop();
            
            else if(s[i]!='#')
                st.push(s[i]);
        }
        
        while(!st.empty())
        {
            p=st.top()+p;
            st.pop();
        }
        
        return p;
    }
    
    bool backspaceCompare(string s, string t) {
        
        string x=convert(s);
        string y=convert(t);
        
        return x==y;
    }
};