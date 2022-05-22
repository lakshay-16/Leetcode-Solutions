// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
bool dfs(int i,int j,string &s,int index,vector<vector<char>> &board)
{
    if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=s[index])
    return false;
    
    if(index==s.length()-1)
    return true;
    
    board[i][j]='#';
    
    bool ans=dfs(i+1,j,s,index+1,board);
    ans=ans||dfs(i+1,j+1,s,index+1,board);
    ans=ans||dfs(i+1,j-1,s,index+1,board);
    ans=ans||dfs(i,j+1,s,index+1,board);
    ans=ans||dfs(i,j-1,s,index+1,board);
    ans=ans||dfs(i-1,j,s,index+1,board);
    ans=ans||dfs(i-1,j+1,s,index+1,board);
    ans=ans||dfs(i-1,j-1,s,index+1,board);
    
    board[i][j]=s[index];
    
    return ans;
}

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<string> ans;
	    set<string> st;
	    unordered_map<char,vector<string>> m;
	    for(auto x:dictionary)
	    m[x[0]].push_back(x);
	    
	    for(int i=0;i<board.size();i++)
	    {
	        for(int j=0;j<board[0].size();j++)
	        if(m.find(board[i][j])!=m.end())
	        {
	            for(int z=0;z<m[board[i][j]].size();z++)
	            if(dfs(i,j,m[board[i][j]][z],0,board))
	            st.insert(m[board[i][j]][z]);
	        }
	        
	    }
	    
	    for(auto x:st)
	    ans.push_back(x);
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends