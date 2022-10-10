//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:    
       bool binary(int i,int e,int arr[],int key)
       {
           int mid;
           
           while(i<=e)
           {
             mid=i+(e-i)/2;
             
             if(arr[mid]==key)
             return true;
             
             if(arr[mid]>key)
             e=mid-1;
             
             else
             i=mid+1;
           }
           
           return false;
       }
    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            vector<int> ans;
            set<int> st;
            for(int i=0;i<n1;i++)
            {
                bool a=binary(0,n2-1,B,A[i]);
                bool b=binary(0,n3-1,C,A[i]);
                
                if(a&&b)
                st.insert(A[i]);
            }
            
            for(auto x:st)
            ans.push_back(x);
            
            return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends