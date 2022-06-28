class Solution {
public:
     void dfs(int i,int j,int parent,vector<vector<bool>> &m,vector<vector<int>> &h)
 {
     if(i<0||i>=h.size()||j<0||j>=h[0].size())
         return;
     
     if(h[i][j]<parent||m[i][j])
         return;
     
     m[i][j]=true;
     
     dfs(i-1,j,h[i][j],m,h);
         dfs(i+1,j,h[i][j],m,h);
         dfs(i,j-1,h[i][j],m,h);
         dfs(i,j+1,h[i][j],m,h);
     
 }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
          int r=heights.size();
        int c=heights[0].size();
        
        vector<vector<int>> ans;
        vector<vector<bool>> pacific(r,vector<bool> (c,false));
         vector<vector<bool>> atlantic(r,vector<bool> (c,false));
        
  for(int i=0;i<r;i++)
  {
      if(pacific[i][0]==false)
          dfs(i,0,heights[i][0],pacific,heights);
  }
        
        
         for(int i=0;i<c;i++)
  {
      if(pacific[0][i]==false)
          dfs(0,i,heights[0][i],pacific,heights);
  }
        
         for(int i=0;i<r;i++)
  {
      if(atlantic[i][c-1]==false)
          dfs(i,c-1,heights[i][c-1],atlantic,heights);
  }
        
         for(int i=0;i<c;i++)
  {
      if(atlantic[r-1][i]==false)
          dfs(r-1,i,heights[r-1][i],atlantic,heights);
  }
        
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(atlantic[i][j]&&pacific[i][j])
                    ans.push_back({i,j});
            }
        }
        
        
        return ans;
    }
};