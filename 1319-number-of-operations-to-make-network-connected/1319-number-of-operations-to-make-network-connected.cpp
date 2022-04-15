class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<bool> &vis)
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
                dfs(adj,x,vis);
        }
        
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        
        vector<int> adj[n];
        int e=c.size();
        for(int i=0;i<e;i++)
        {
            adj[c[i][0]].push_back(c[i][1]);
            adj[c[i][1]].push_back(c[i][0]);
        }
        
        vector<bool> vis(n,false);
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(adj,i,vis);
                count++;
            }
            
        }
        
        
        if(count==1)
            return 0;
        
        
        int extra=count-1;
        int grouped=n-extra;
        
        if(e-grouped+1>=extra)
            return extra;
        
        
        
        
        
        return -1;
        
        
    }
};