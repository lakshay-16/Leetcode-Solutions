// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool inbound(int i,int j,int r,int c)
  {
      return (i>=0&&j>=0&&i<r&&j<c);
  }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0]==0)
        return -1;
        
        vector<vector<bool>> vis(N,vector<bool> (M,false));
        queue<pair<pair<int,int>,int>> pq;
        pq.push({{0,0},0});
        vis[0][0]=true;
        
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};
        int ans=INT_MAX;
        
        while(!pq.empty())
        {
            pair<int,int> p=pq.front().first;
            int dist=pq.front().second;
            int x=p.first;
            int y=p.second;
            pq.pop();
            
            if(x==X&&y==Y)
            ans=min(ans,dist);
            
            for(int i=0;i<4;i++)
            {
                int cx=x+dx[i];
                int cy=y+dy[i];
                
                if(inbound(cx,cy,N,M)&&!vis[cx][cy]&&A[cx][cy]==1)
                {
                    pq.push({{cx,cy},dist+1});
                    vis[cx][cy]=true;
                }
            }
            
            
        }
        
        if(ans==INT_MAX)
        return -1;
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends