class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
       
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            if(i==headID)
                continue;
            
            adj[manager[i]].push_back(i);
        }
         
        int ans=INT_MIN;
        queue<pair<int,int>> pq;
        pq.push({headID,0});
        
        while(!pq.empty())
        {
            int node=pq.front().first;
            int waittime=pq.front().second;
            pq.pop();
            ans=max(ans,waittime);
            
            for(auto x:adj[node])
                pq.push({x,waittime+informTime[node]});
        }
        
        
        return ans;
    }
};