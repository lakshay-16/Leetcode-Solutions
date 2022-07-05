class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &vis,long long &count)
    {
        if(vis[node])
            return;
        
        vis[node]=1;
        count++;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
                dfs(x,adj,vis,count);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        long long ans=0;
        vector<int> adj[n];
        
        long long a=n;
            ans=(a*(a-1))/2;
        
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
       
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            long long count=0;
            if(!vis[i])
                dfs(i,adj,vis,count);
            
            ans-=(count*(count-1))/2;
        }
        
        return ans;
    }
};