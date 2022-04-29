class Solution {
public:
    
    vector<int> dx={0,0,-1,1};
    vector<int> dy={-1,1,0,0};
    
    bool inbound(int i,int j,int r,int c)
    {
        return (i>=0&&j>=0&&i<r&&j<c);
    }
    
    bool bfs(vector<vector<int>> &heights,int mid)
    {
        int r=heights.size();
        int c=heights[0].size();
        
        vector<vector<bool>> vis(r,vector<bool> (c,false));
        queue<pair<int,int>> pq;
        
        vis[0][0]=true;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            
            if(x==r-1&&y==c-1)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                if(inbound(cx,cy,r,c)&&!vis[cx][cy])
                {
                    int dif=abs(heights[cx][cy]-heights[x][y]);
                    if(dif<=mid)
                    {
                        vis[cx][cy]=true;
                        pq.push({cx,cy});
                    }
                }
                
            }
            
        }
        
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int i=0;
        int e=1e6;
        int ans=-1;
        
        while(i<=e)
        {
            int mid=i+(e-i)/2;
            
            if(bfs(heights,mid))
            {
                ans=mid;
                e=mid-1;
            }
            
            else
                i=mid+1;
            
        }
        
        return ans;
    }
};