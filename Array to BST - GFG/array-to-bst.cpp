// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
void preorder(int i,int e,vector<int> &nums,vector<int>& g)
{
    if(i>e||i<0||e>=nums.size())
    return;
    
    int mid=i+(e-i)/2;
    g.push_back(nums[mid]);
    preorder(i,mid-1,nums,g);
    preorder(mid+1,e,nums,g);
}

    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int> g;
        int i=0;
        int e=nums.size()-1;
        preorder(i,e,nums,g);
        
        return g;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends