class Solution {
public:
    
    bool inbound(int i,int j,int r,int c)
    {
        if(i<0||j<0||i>=r||j>=c)
            return false;
        
        return true;
    }

    void dfs(int i,int j,vector<vector<int>> &board,vector<vector<bool>> &g)
    {   
          vector<int> dx={1,1,1,0,0,-1,-1,-1};
        vector<int> dy={1,0,-1,1,-1,1,0,-1};
        
        int count=0;
        
        for(int x=0;x<8;x++)
        {
            int cx=i+dx[x];
            int cy=j+dy[x];
            
            if(inbound(cx,cy,board.size(),board[0].size())&&board[cx][cy]==1)
                count++;
        }
        
        if(board[i][j]==0&&count==3)
            g[i][j]=true;
        
        if(board[i][j]==1&&count>=2&&count<=3)
            g[i][j]=true;
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        
     
        
        int r=board.size();
        int c=board[0].size();
        vector<vector<bool>> one(r,vector<bool>(c));
        
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
dfs(i,j,board,one);
            }
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(one[i][j])
                board[i][j]=1;
                
                else
                    board[i][j]=0;
            }
        }
        
        
        
        
    }
};