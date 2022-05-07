// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1)
        return 0;
        if(arr[0]==0)
        return -1;
        
        int range=arr[0];
        int steps=arr[0];
        int jump=1;
        
        for(int j=1;j<n;j++)
        {
            if(j==n-1)
            return jump;
            
            range=max(range,j+arr[j]);
            steps--;
            
            if(steps==0)
            {
                jump++;
                if(range<=j)
                return -1;
                steps=range-j;
            }
        }
        
        return -1;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends