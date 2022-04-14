class Solution {
public:
    
    void dfs(int i,int j,vector<vector<char>> &vis,vector<vector<int>> &st)
    {
        if(i<0||j<0||i>=vis.size()||j>=vis[0].size())
            return;
        
        if(vis[i][j]!='O')
            return;
            
        vis[i][j]='$';
            st[i][j]=1;
        
        dfs(i+1,j,vis,st);
         dfs(i-1,j,vis,st);
         dfs(i,j+1,vis,st);
         dfs(i,j-1,vis,st);
    }
    
    void solve(vector<vector<char>>& board) {
       
        int r=board.size();
        int c=board[0].size();
         vector<vector<int>> set(r,vector<int> (c,0));
        vector<vector<char>> vis=board;
        
        for(int i=0;i<r;i++)
        {
            if(vis[i][0]=='O')
                dfs(i,0,vis,set);
        }
        
          for(int i=0;i<r;i++)
        {
            if(vis[i][c-1]=='O')
                dfs(i,c-1,vis,set);
        }
        
        for(int i=0;i<c;i++)
        {
            if(vis[0][i]=='O')
                dfs(0,i,vis,set);
        }
        
           for(int i=0;i<c;i++)
        {
            if(vis[r-1][i]=='O')
                dfs(r-1,i,vis,set);
        }
        
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='O'&&set[i][j]==0)
                    board[i][j]='X';
            }
        }
        
        
        
        
        
        
    }
};