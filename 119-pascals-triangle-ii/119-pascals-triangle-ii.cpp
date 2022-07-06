class Solution {
public:
    vector<int> getRow(int rowIndex) {
          vector<vector<int>> ans;
        
        for(int i=0;i<=rowIndex;i++)
        {
            vector<int> g(i+1,1);
            ans.push_back(g);
        }
        
        
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=1;j<ans[i].size()-1;j++)
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        
        return ans[rowIndex];
    }
};