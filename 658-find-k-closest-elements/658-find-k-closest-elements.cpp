class Solution {
public:
     
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<pair<int,int>> m;
        vector<int> g;
        for(int i=0;i<arr.size();i++)
        {
            int dif=abs(arr[i]-x);
            m.push_back({dif,arr[i]});
        }
        
        sort(m.begin(),m.end());
        
        for(int i=0;i<k;i++)
            g.push_back(m[i].second);
        
        sort(g.begin(),g.end());
        
        
        return g;
    }
};