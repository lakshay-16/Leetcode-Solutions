// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<=n-4;i++)
        {
            for(int j=i+1;j<=n-3;j++)
            {
                int left=j+1;
                int right=n-1;
                
                while(left<right)
                {
                 if(arr[i]+arr[j]+arr[left]+arr[right]==k)
                 {
                     s.insert({arr[i],arr[j],arr[left],arr[right]});
                     left++;
                     right--;
                 }
                    
                    else if(arr[i]+arr[j]+arr[left]+arr[right]<k)
                    left++;
                    
                    else
                    right--;
                }
            }
        }
        
        for(auto x:s)
        ans.push_back(x);
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends