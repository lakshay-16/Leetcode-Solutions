class Solution {
public:
    bool inbound(int i ,int j,int r,int c)
    {
        return (i>=0&&i<r&&j>=0&&j<c);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        
        if(grid[0][0]==1)
            return -1;
        
        vector<vector<bool>> vis(r,vector<bool> (c,false));
        
        queue<pair<pair<int,int>,int>> pq;
        pq.push({{0,0},1});
        
        
        vector<int> dx={1,1,1,0,0,-1,-1,-1};
        vector<int> dy={1,0,-1,1,-1,1,0,-1};
        
        
        int ans=INT_MIN;
        vis[0][0]=true;
        while(!pq.empty())
        {
            pair<int,int> q=pq.front().first;
            int val=pq.front().second;
            int i=q.first;
            int j=q.second;
            pq.pop();
            
            if(i==r-1&&j==c-1)
                ans=max(ans,val);
            
            for(int z=0;z<8;z++)
            {
                int cx=i+dx[z];
                int cy=j+dy[z];
                
                if(inbound(cx,cy,r,c)&&grid[cx][cy]==0&&!vis[cx][cy])
                {pq.push({{cx,cy},val+1});
            vis[cx][cy]=true;
                }
                
            }
                
        }
        
        if(ans==INT_MIN)
            return -1;
        
        return ans;
    }
};