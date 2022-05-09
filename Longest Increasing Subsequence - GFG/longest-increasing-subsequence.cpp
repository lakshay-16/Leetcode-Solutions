// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int index,int prev,int a[],int n,vector<vector<int>> &dp)
    {
        if(index==n)
        return 0;
        
        if(dp[index][prev+1]!=-1)
        return dp[index][prev+1];
        
        int len=0+solve(index+1,prev,a,n,dp);
        if(prev==-1||a[index]>a[prev])
        len=max(len,1+solve(index+1,index,a,n,dp));
        
        return dp[index][prev+1]=len;
    }
    
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int> (n+1,-1));
       return solve(0,-1,a,n,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends