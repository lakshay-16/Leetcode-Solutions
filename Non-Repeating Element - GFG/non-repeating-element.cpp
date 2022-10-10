//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        queue<int> pq;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
            m[arr[i]]++;
        }
        
        while(!pq.empty()&&m[pq.front()]>1)
        pq.pop();
        
        return (pq.empty())?0:pq.front();
    } 
  
};


//{ Driver Code Starts.

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.firstNonRepeating(arr,n)<<endl;
    }
}

// } Driver Code Ends