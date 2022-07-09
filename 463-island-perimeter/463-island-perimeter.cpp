class Solution {
public:
    bool inbound(int i,int j,int n,int m)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<pair<int,int>> g;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
                    g.push_back({i,j});
        }
        
        
        int ans=0;
        vector<int> dx={0,0,-1,1};
        vector<int> dy={-1,1,0,0};
        
        for(auto x:g)
        {
            int y=4;
            for(int i=0;i<4;i++)
            {
                int cx=x.first+dx[i];
                int cy=x.second+dy[i];
                
                if(inbound(cx,cy,n,m)&&grid[cx][cy]==1)
                y--;
            }
            
            ans+=y;
        }
        
        
        return ans;
    }
};