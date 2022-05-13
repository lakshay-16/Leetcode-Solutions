class FindSumPairs {
public:
    vector<int> g1,g2;
    unordered_map<int,int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        g2=nums2;
        g1=nums1;
        
        for(auto x:nums2)
            m[x]++;
    }
    
    void add(int index, int val) {
        if(m[g2[index]]>0)
            m[g2[index]]--;
        
        g2[index]+=val;
        
        m[g2[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto x:g1)
        {
            if(m.find(tot-x)!=m.end())
                ans+=m[tot-x];
        }
        
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */