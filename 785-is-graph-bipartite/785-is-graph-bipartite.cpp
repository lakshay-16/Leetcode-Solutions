class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int V=graph.size();
        vector<int> color(V,-1);
        queue<pair<int,int>> pq;
    
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            pq.push({i,0});
        }
    
    while(!pq.empty())
    {
        int node=pq.front().first;
        int col=pq.front().second;
        
        pq.pop();
        
        for(auto x:graph[node])
        {
            if(color[x]==col)
                return false;
            
            else if(color[x]==-1)
            {
                color[x]=col^1;
                pq.push({x,color[x]});
            }
        }
        
    }
        
    }
    
        
        
        
    return true;
    }
    
};