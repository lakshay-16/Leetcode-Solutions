class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int sm=INT_MIN;
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(sm>nums[i])
                return true;
            
            while(!st.empty()&&nums[i]>st.top())
            {
                sm=max(sm,st.top());
                st.pop();
            }
            
            st.push(nums[i]);
        }

        return false;
    }
};