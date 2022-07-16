class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            
                if(s[i]==')'&&!st.empty())
                {
                    if(st.top()!='(')
                        return false;
                    
                    else 
                        st.pop();
                }
                
                 else if(s[i]==']'&&!st.empty())
                {
                    if(st.top()!='[')
                        return false;
                    
                    else 
                        st.pop();
                }
                
                 else if(s[i]=='}'&&!st.empty())
                {
                    if(st.top()!='{')
                        return false;
                    
                    else 
                        st.pop();
                }
            
            
            else
            st.push(s[i]);
        }
        
        
        return st.empty();
    }
};