// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        stack<long long> st;
        vector<long long> g;
        
        for(int i=0;i<n;i++)
        {
            if(st.size()==k)
            {
                while(!st.empty())
                {
                g.push_back(st.top());
                st.pop();
                }
                
                }
        
            
            st.push(arr[i]);
        }
        
        while(!st.empty())
        {
            g.push_back(st.top());
            st.pop();
        }
        
        arr=g;
    }
};

// { Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
}

  // } Driver Code Ends