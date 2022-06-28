class Solution {
public:
    bool inbound(int i,int j,int n,int m)
    {
        return (i>=0&&i<n&&j>=0&&j<m);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        
        queue<pair<int,int>> pq;
        vector<vector<int>> dist(n,vector<int> (m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    pq.push({i,j});
                }
            }
        }
        
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,-1,1};
        
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            
            for(int i=0;i<4;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                if(inbound(cx,cy,n,m)&&dist[cx][cy]==-1)
                {
                    pq.push({cx,cy});
                    dist[cx][cy]=dist[x][y]+1;
                }
                
            }
            
        }
        
        
        return dist;
    }
};