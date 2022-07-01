class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[])
    {
        vis[node]=true;
        
        for(auto x:adj[node])
        if(!vis[x])
            dfs(x,vis,adj);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(i!=j&&isConnected[i][j]==1)
                    adj[i].push_back(j);
        }
        
        vector<int> vis(n,0);
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            { dfs(i,vis,adj);
        count++;
            }
            
        }
        
        return count;
    }
};