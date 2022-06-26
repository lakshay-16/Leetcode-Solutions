class Solution {
public:
   void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int row,int col,int& flag){
        if(row<0 || col<0 || row>=grid2.size() || col >=grid2[0].size()) return;
        if(grid2[row][col]==0) return;
        
        if(grid2[row][col]==1){
            if(grid1[row][col]==0){flag=0;return;}
            grid2[row][col]=0;
       }
                    
            dfs(grid1,grid2,row+1,col,flag);
            dfs(grid1,grid2,row-1,col,flag);
            dfs(grid1,grid2,row,col+1,flag);
            dfs(grid1,grid2,row,col-1,flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
          int count=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[0].size();j++){
                int flag=1;
                if(grid2[i][j]==1){
                    dfs(grid1,grid2,i,j,flag);
                    if(flag) count++;
                }
            }
        }
        return count;
      
    }
};