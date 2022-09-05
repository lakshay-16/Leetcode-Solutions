class Solution {
public:
    int ans=0;
    
    void solve(vector<vector<int>> &mat,vector<int> &vis,int col,int r,int c,int cols)
    {
        if(cols==0)
        {
            int rows=count(mat,r,c,vis);
            ans=max(ans,rows);
            return;
        }
        
        if(col>=c)
            return;
        
        solve(mat,vis,col+1,r,c,cols);
        
        vis[col]=1;
        solve(mat,vis,col+1,r,c,cols-1);
        vis[col]=0;
    }
    
    int count(vector<vector<int>> &mat,int r,int c,vector<int> &vis)
    {
        int g=0;
        for(int i=0;i<r;i++)
        {
            bool flag=true;
            for(int j=0;j<c;j++)
            if(mat[i][j]==1&&vis[j]==0)
            {
                flag=false;
                break;
            }
            
            if(flag)
                g++;
        }
        
        return g;
    }
    
    int maximumRows(vector<vector<int>>& mat, int cols) {
        ans=0;int r=mat.size();
        int c=mat[0].size();
        vector<int> vis(c,0);
        solve(mat,vis,0,r,c,cols);
        
        return ans;
    }
};