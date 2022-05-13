// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        int sum=0,sum1=0;
	    for(int i=0;i<n;i++)
	        sum+=A[i];
	       
	   for(int j=0;j<m;j++)
	        sum1+=B[j];
	       
	   unordered_map<int,int> mp;
	   for(int i=0;i<n;i++)
	    mp[A[i]]++;
	   
	   for(int i=0;i<m;i++)
	   {
	       int diff=sum-sum1+2*B[i];
	       
	       if(diff%2==0 && mp.count((diff)/2)!=0)
	        return 1;
	        
	   }
	   
	   return -1;
	}
 

};

// { Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}





  // } Driver Code Ends