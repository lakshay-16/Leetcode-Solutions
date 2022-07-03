class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      
        set<pair<int,int>> st;
        vector<int> adj[n];
        
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            
            st.insert({connections[i][0],connections[i][1]});
        }
        
        vector<bool> vis(n,false);
        
        queue<int> pq;
        pq.push(0);
        vis[0]=true;
        int count=0;
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            for(auto x:adj[node])
            {
                if(!vis[x])
                {
                    if(st.find({node,x})!=st.end())
                        count++;
                    
                    vis[x]=true;
                    pq.push(x);
                }
            }
            
        }
        
        
        return count;
    }
};