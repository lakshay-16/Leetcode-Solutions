class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> g;
        
        for(int i=0;i<l.size();i++)
        {
            vector<int> v;
            for(int j=l[i];j<=r[i];j++)
            v.push_back(nums[j]);
            
            sort(v.begin(),v.end());
            
            int dif=v[1]-v[0];
            bool flag=true;
            
            for(int j=1;j<v.size()-1;j++)
            { if(v[j+1]-v[j]!=dif)
            flag=false;}
            
            g.push_back(flag);
        }
        
        
        return g;
    }
};