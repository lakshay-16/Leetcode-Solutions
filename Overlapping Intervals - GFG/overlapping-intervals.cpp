// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
static bool comp(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])
    return a[1]<b[1];
    
    return a[0]<b[0];
}

    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         // Code here
         int n=intervals.size();
         vector<vector<int>> ans;
         int x,j;
         
         sort(intervals.begin(),intervals.end(),comp);
         
         x=intervals[0][0];
         j=intervals[0][1];
         
         for(int i=1;i<intervals.size();i++)
         {
             
             if(j>intervals[i][0]&&j>=intervals[i][1])
             continue;
             
            else if(j>=intervals[i][0]&&j<=intervals[i][1])
             {
             j=intervals[i][1];
             continue;
             }
         
         else
         {
             ans.push_back({x,j});
             x=intervals[i][0];
             j=intervals[i][1];
         }
             
         }
         
         
         ans.push_back({x,j});
         
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends