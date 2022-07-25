class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> g;
        int i=0,j=0;
        
        while(i<m&&j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                g.push_back(nums1[i]);
                i++;
            }
            
            else
            {
                g.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<m)
        {
            g.push_back(nums1[i]);
                i++;
        }
        
        
        while(j<n)
        {
             g.push_back(nums2[j]);
                j++;
        }
        
        nums1=g;
    }
};