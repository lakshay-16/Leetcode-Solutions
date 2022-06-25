class Solution {
public:
      bool helper(int i,int j,const int &n,const int &m,vector<vector<int>>& a){
        bool l = true,r = true,t = true,b = true;
        a[i][j] = 2;
        if(i != 0 && a[i - 1][j] == 0) t = helper(i - 1,j,n,m,a);
        if(i != n-1 && a[i + 1][j] == 0) b = helper(i+1,j,n,m,a);
        if(j != 0 && a[i][j - 1] == 0) l = helper(i,j - 1,n,m,a);
        if(j != m-1 && a[i][j + 1] == 0) r =helper(i,j + 1,n,m,a);
        if(i == 0 || j == 0 || i == n - 1 || j == m - 1) return false; 
        return r && l && b && t;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
         const int n = grid.size(),m = grid[0].size();
        int ans = 0;
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(grid[i][j] == 0 && helper(i,j,n,m,grid)) ans++;
        return ans;
      
    }
};