class Solution {
public:  
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> rec[101];
        for(auto x:rectangles)
        {
            int x1=x[0];
            int y1=x[1];
            rec[y1].push_back(x1);
        }
     
        for(int i=0;i<=100;i++)
            sort(rec[i].begin(),rec[i].end());
        
        vector<int> ans;
        
        for(auto x:points)
        {
            int x1=x[0];
            int y1=x[1];
            
            int k=0;
            for(int i=y1;i<101;i++)
                k+=rec[i].end()-lower_bound(rec[i].begin(),rec[i].end(),x1);
            
            ans.push_back(k);
        }
        
        return ans;
    }
};