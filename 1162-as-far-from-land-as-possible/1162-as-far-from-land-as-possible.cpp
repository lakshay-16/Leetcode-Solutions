class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,-1,1};
    
    int maxDistance(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            if(grid[i][j]==1)
            { pq.push({i,j});
             dist[i][j]=0;
            }
            
            }
        
        
        int ans=0;
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                
                if(cx>=0&&cx<n&&cy>=0&&cy<m&&dist[cx][cy]==INT_MAX)
                {
                    pq.push({cx,cy});
                    dist[cx][cy]=dist[x][y]+1;
                    
                    ans=max(ans,dist[cx][cy]);
                }
                
            }
        }
        
        
        if(ans==0||ans==INT_MAX)return -1;
        
        return ans;
        
        
    }
};