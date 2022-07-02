class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    
          int n=graph.size();
                   vector<int> outdegree(n,0);
        queue<int> pq;
        vector<int> ans;
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)    
        { 
            outdegree[i]=graph[i].size();
            for(auto x:graph[i])
                adj[x].push_back(i);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(outdegree[i]==0)
                pq.push(i);
        }
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            ans.push_back(node);
            
            for(auto x:adj[node])
            {
                outdegree[x]--;
                
                if(outdegree[x]==0)
                pq.push(x);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
      
    }
};