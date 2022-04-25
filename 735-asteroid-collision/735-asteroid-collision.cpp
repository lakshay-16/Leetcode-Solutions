class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        for(auto it:asteroids)
        {
            if( it > 0) st.push(it);
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -it){
                    st.pop();
                }
                if(!st.empty() && st.top() == -it) st.pop();
                else if(!st.empty() && st.top() > -it) continue;
                else st.push(it);
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};