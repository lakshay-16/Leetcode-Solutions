class Solution {
public:
    
    void dfs(vector<int> adj[],string &s,int vertex,vector<char> &c,vector<int> &i,vector<bool> &vis)
    {
        vis[vertex]=true;
        
        c.push_back(s[vertex]);
        i.push_back(vertex);
        
        for(auto x:adj[vertex])
        {
            if(!vis[x])
                dfs(adj,s,x,c,i,vis);
        }
        
    }
        
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.size();
        vector<int> adj[n];
        vector<bool> vis(n,false);
        
        for(int i=0;i<pairs.size();i++)
        {
            adj[pairs[i][0]].push_back(pairs[i][1]);
             adj[pairs[i][1]].push_back(pairs[i][0]);
        }
        
        for(int i=0;i<n;i++)
        {
            
            if(!vis[i])
            {
                vector<char> c;
                vector<int> g;
                
                dfs(adj,s,i,c,g,vis);
                
                
                sort(c.begin(),c.end());
                sort(g.begin(),g.end());
                
                
                for(int j=0;j<c.size();j++)
                s[g[j]]=c[j];
            }
            
        }
        
        return s;
    }
};