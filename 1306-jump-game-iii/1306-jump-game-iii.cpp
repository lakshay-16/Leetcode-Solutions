class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n=arr.size();
        queue<pair<int,int>> pq;
        pq.push({arr[start],start});
        vector<int> vis(n,0);
        
        while(!pq.empty())
        {
            int node=pq.front().first;
            int index=pq.front().second;
            pq.pop();
            
            vis[index]=true;
            
            if(node==0)
                return true;
            
            int i=index-node;
            int e=index+node;
            
            if(i>=0&&!vis[i])
                pq.push({arr[i],i});
            
            if(e<n&&!vis[e])
                pq.push({arr[e],e});
        }
        
        return false;
    }
};