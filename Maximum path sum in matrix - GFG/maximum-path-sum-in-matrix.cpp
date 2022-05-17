// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i ,int j,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(i<0||i>=matrix.size()||j<0||j>=matrix[0].size())
    return 0;
    
    if(i==matrix.size()-1)
    return matrix[i][j];
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int a=matrix[i][j]+solve(i+1,j,matrix,dp);
    int b=matrix[i][j]+solve(i+1,j-1,matrix,dp);
    int c=matrix[i][j]+solve(i+1,j+1,matrix,dp);
    
    return dp[i][j]=max(a,max(b,c));
}

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int r=Matrix.size();
        int c=Matrix[0].size();
        vector<vector<int>> dp(r,vector<int> (c,-1));
        
        int ans=0;
        for(int i=0;i<r;i++)
        ans=max(ans,solve(0,i,Matrix,dp));
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends