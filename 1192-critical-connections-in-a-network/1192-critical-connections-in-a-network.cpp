class Solution {
public:
    vector<int> first,mini,vis; 
     vector<vector<int>> ans;
    int time=0;
    void dfs(int node,vector<int> adj[],int parent=-1)
    {
   first[node]=mini[node]=time++;
        vis[node]=true;
        
        for(auto x:adj[node])
        {
            if(x==parent)
                continue;
            
            if(!vis[x])
                dfs(x,adj,node);
            
            mini[node]=min(mini[node],mini[x]);
            
            if(first[node]<mini[x])
                ans.push_back({node,x});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
       
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            int x=connections[i][0];
            int y=connections[i][1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        first.resize(n),vis.resize(n),mini.resize(n);  
        dfs(0,adj);
        return ans;
    }
};