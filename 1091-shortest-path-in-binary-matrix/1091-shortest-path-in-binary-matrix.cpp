class Solution {
public:
    bool inbound(int i,int j,int n,int m)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1)
            return -1;
        
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        
        dist[0][0]=1;
        queue<pair<int,int>> pq;
        pq.push({0,0});
        int ans=INT_MAX;
        
         vector<int> dx={1,1,1,0,0,-1,-1,-1};
        vector<int> dy={1,0,-1,1,-1,1,0,-1};
        
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            
            if(x==n-1&&y==m-1)
                ans=min(ans,dist[x][y]);
        
            
            for(int i=0;i<8;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                
                if(inbound(cx,cy,n,m)&&dist[cx][cy]==INT_MAX&&grid[cx][cy]==0)
                {
                    pq.push({cx,cy});
                    dist[cx][cy]=dist[x][y]+1;
                }
                
            }
            
        }
        
        if(ans==INT_MAX)
            return -1;
        
        return ans;
    }
};