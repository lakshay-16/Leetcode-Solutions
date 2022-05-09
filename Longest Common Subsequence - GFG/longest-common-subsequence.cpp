// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int index1,int index2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(index1<0||index2<0)
        return 0;
        
        if(dp[index1][index2]!=-1)
        return dp[index1][index2];
        
        if(s1[index1]==s2[index2])
        return dp[index1][index2]=1+solve(index1-1,index2-1,s1,s2,dp);
        
        return dp[index1][index2]=0+max(solve(index1-1,index2,s1,s2,dp),solve(index1,index2-1,s1,s2,dp));
    }
    
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(x,vector<int> (y,-1));
        return solve(x-1,y-1,s1,s2,dp);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends