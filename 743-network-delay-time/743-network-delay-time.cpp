class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int j=times[i][0];
            adj[j].push_back({times[i][1],times[i][2]});
        }
        
        vector<int> dist(n+1,INT_MAX);
        
        dist[k]=0;
        queue<int> pq;
        pq.push(k);
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            for(pair<int,int> p:adj[node])
            {
                int v=p.first;
                int val=p.second;
                int nval=val+dist[node];
                if(nval<dist[v])
                {  dist[v]=nval;
                 pq.push(v);
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            
            ans=max(ans,dist[i]);
        }
        
        return ans;
    }
};