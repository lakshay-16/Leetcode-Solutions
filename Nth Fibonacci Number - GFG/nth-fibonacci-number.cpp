// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthFibonacci(long long int n){
        // code here
        long long int dp[1001];
        long long int mod=1e9+7;
        dp[0]=0;
        dp[1]=1;
        
        for(long long int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends