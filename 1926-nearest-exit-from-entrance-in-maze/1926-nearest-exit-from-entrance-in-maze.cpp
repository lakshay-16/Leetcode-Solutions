class Solution {
public:
    bool inbound(int i,int j,int n,int m)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
      
        int n=maze.size();
        int m=maze[0].size();
        
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
      
        
        int ex=entrance[0];
        int ey=entrance[1];
        
        dist[ex][ey]=0;
        
        queue<pair<int,int>> pq;
        pq.push({ex,ey});
        int ans=INT_MAX;
        
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};
        
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            
            
            if(dist[x][y]!=0&&(x==n-1||y==m-1||x==0||y==0))
                ans=min(ans,dist[x][y]);
            
            
            for(int i=0;i<4;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                if(inbound(cx,cy,n,m)&&dist[cx][cy]==INT_MAX&&maze[cx][cy]=='.')
                {
                    pq.push({cx,cy});
                    dist[cx][cy]=1+dist[x][y];
                }
            }
            
        }
        
        return (ans==INT_MAX)?-1:ans;
    }
};