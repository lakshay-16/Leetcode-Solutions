class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> m;
        stack<int> st;
        int n=nums2.size();
        
        m[nums2[n-1]]=-1;
        st.push(nums2[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums2[i])
                st.pop();
            
            if(st.empty())
                m[nums2[i]]=-1;
            
            else
                m[nums2[i]]=st.top();
            
            st.push(nums2[i]);
        }
        
        
        vector<int> ans;
        for(auto x:nums1)
        ans.push_back(m[x]);
        
        return ans;
    }
};