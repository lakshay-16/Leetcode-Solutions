class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
                dfs(x,vis,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int edges=connections.size();
        
        if(edges<n-1)
            return -1;
        
        vector<int> vis(n,0);
        vector<int> adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
             adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {dfs(i,vis,adj);
            count++;
            }
        }
        
        int dif=count-1;
        
        return dif;
    }
};