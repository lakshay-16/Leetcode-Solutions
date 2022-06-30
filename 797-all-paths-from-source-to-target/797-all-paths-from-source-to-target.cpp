class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int> &g,int n,vector<vector<int>> &ans)
    {
        g.push_back(node);
        
        if(node==n-1)
            ans.push_back(g);
        
        for(auto x:adj[node])
            dfs(x,adj,g,n,ans);
        
        
        g.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        int n=graph.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
                adj[i].push_back(graph[i][j]);
        }
        
        vector<int> g;
        dfs(0,adj,g,n,ans);
        
        return ans;
    }
};