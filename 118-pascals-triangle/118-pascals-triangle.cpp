class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        for(int i=1;i<=numRows;i++)
        {
            vector<int> g(i,1);
            ans.push_back(g);
        }
        
        
        for(int i=2;i<ans.size();i++)
        {
            for(int j=1;j<ans[i].size()-1;j++)
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        
     return ans;
    }
};