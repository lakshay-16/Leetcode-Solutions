// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(V, -1);
        vector<bool> mst(V, false);
        vector<int> key(V, INT_MAX);
        
        key[0] = 0;
        parent[0] = -1;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        pq.push({0,0}); 
        
     
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            mst[u] = true;
            for(auto it: adj[u])
            {
                int v = it[0];
                int wt = it[1];
                if(mst[v] == false && wt < key[v])
                {
                    key[v] = wt;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
        
        int sum = accumulate(key.begin(), key.end(), 0LL);
        return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends