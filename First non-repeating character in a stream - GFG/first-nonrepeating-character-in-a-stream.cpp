// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> pq;
		    unordered_map<char,int> m;
		    string ans="";
		    
		    for(int i=0;i<A.size();i++)
		    {
		        m[A[i]]++;
		        
		        if(m[A[i]]==1)
		        pq.push(A[i]);
		        
		        while(!pq.empty()&&m[pq.front()]!=1)
		        pq.pop();
		        
		        ans+=pq.empty()?'#':pq.front();
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends