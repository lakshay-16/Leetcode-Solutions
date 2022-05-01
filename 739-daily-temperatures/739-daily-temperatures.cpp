class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans;
        int n=temperatures.size();
        st.push({temperatures[n-1],n-1});
        ans.push_back(0);
        
        for(int i=n-2;i>=0;i--)
        {
            int count=0;
            while(!st.empty()&&st.top().first<=temperatures[i])
                st.pop();
            
            if(st.empty())
                count=0;
            
            else
                count=st.top().second-i;
            
            ans.push_back(count);
            st.push({temperatures[i],i});
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};