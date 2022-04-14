class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<int> ans;
        vector<int> adj[n+1];
        for(int i=0;i<paths.size();i++)
        {
            adj[paths[i][0]].push_back(paths[i][1]);
            adj[paths[i][1]].push_back(paths[i][0]);
        }
        
        vector<int> vis(n+1,0);
        queue<int> pq;
        
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                queue<int> pq;
                pq.push(i);
                
                while(!pq.empty())
                {
                    int node=pq.front();
                    pq.pop();
                    
                    for(auto x:adj[node])
                    {
                        if(vis[x]==0)
                        {
                            vis[x]=vis[node]+1;
                            pq.push(x);
                        }
                        
                        else if(vis[x]==vis[node])
                        {
                            vis[x]=vis[node]+1;
                            pq.push(x);
                        }
                        
                        if(vis[x]>4)
                            vis[x]=vis[x]%4;
                    }
                    
                }
                
                
            }
        }
            
        vis.erase(vis.begin());
        
        return vis;
        
        
    }
};