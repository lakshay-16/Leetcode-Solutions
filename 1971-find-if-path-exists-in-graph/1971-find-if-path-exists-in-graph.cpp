class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> pq;
        pq.push(source);
        vector<bool> vis(n,false);
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            vis[node]=true;
            
            if(node==destination)
                return true;
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                    pq.push(x);
            }
            
            
        }
        
        
        return false;
        
    }
};