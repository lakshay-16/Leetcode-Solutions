// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
unordered_map<string,int> m;
int dp[1101];
    int solve(string &a,int index)
    {
        if(index==a.size())
        return 1;
        
        string temp="";
        if(dp[index]!=-1)
        return dp[index];
        
        for(int i=index;i<a.size();i++)
        {
            temp+=a[i];
            if(m.find(temp)!=m.end())
            {
                if(solve(a,i+1))
                return dp[index]=1;
            }
        }
        
        return dp[index]=0;
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        
        for(auto x:B)
        m[x]++;
        
        memset(dp,-1,sizeof(dp));
        return solve(A,0);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends