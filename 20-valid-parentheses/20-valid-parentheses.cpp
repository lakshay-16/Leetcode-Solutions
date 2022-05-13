class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        st.push('a');
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==')')
            {
                if(st.top()!='(')
                    return false;
                
                st.pop();
            }
            
            else if(s[i]==']')
            {
                if(st.top()!='[')
                    return false;
                
                st.pop();
            }
            
            else if(s[i]=='}')
            {
                if(st.top()!='{')
                    return false;
                
                st.pop();
            }
            
            else
                st.push(s[i]);
        }
        
        
        if(st.top()=='a')
            return true;
        
        return false;
    }
};