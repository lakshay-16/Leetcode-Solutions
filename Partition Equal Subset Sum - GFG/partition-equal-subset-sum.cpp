// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(int index,int sum,int arr[],vector<vector<int>> &dp)
{
    if(sum==0)
    return 1;
    
    if(index==0)
    return (arr[0]==sum);
    
    if(dp[index][sum]!=-1)
    return dp[index][sum];
    
    bool nottake=solve(index-1,sum,arr,dp);
    bool take=0;
    if(arr[index]<=sum)
    take=solve(index-1,sum-arr[index],arr,dp);
    
    return dp[index][sum]=(nottake||take);
}



    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        if(sum%2!=0)
        return 0;
        
        int dpsum=sum/2;
        vector<vector<int>> dp(N,vector<int> (dpsum+1,-1));
        
        return solve(N-1,dpsum,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends