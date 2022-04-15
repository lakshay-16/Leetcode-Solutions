class Solution {
public:    
    bool dfs(vector<int> adj[],int node,int parent,vector<bool> &vis)
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(!vis[x])
            {
     if(dfs(adj,x,node,vis))
         return true;
            }
            
            else if(x!=parent)
            return true;
        }
        
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) { 
       
        int n=edges.size();
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n+1,false);
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            
            if(dfs(adj,edges[i][0],-1,vis))
                return edges[i];
        }
        
        
        return {};
    }
};