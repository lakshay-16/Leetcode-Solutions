class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<bool> mst(n,false);
        
        int ans=0;
        int edges=0;
        
        pq.push({0,0});
        
        while(edges<n)
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int node=p.second;
            int weight=p.first;
            
            if(mst[node])
                continue;
            
            mst[node]=true;
            ans+=weight;
            edges++;
            
           for(int i=0;i<n;i++)
           {
               if(!mst[i])
               {
                   int x=abs(points[i][0]-points[node][0])+abs(points[i][1]-points[node][1]);
                   pq.push({x,i});
               }
           }
            
        }
        
        return ans;
    }
};