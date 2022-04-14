// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

bool dfs(int i,int j,vector<vector<char>> &board,string &word,int index)
{
    if(i<0||j<0||i>=board.size()||j>=board[0].size())
    return false;
    
    if(board[i][j]!=word[index])
    return false;
    
    if(index==word.length()-1)
    return true;
    
    board[i][j]='$';
    
    bool result=dfs(i+1,j,board,word,index+1);
    result=result||dfs(i-1,j,board,word,index+1);
    result=result||dfs(i,j+1,board,word,index+1);
    result=result||dfs(i,j-1,board,word,index+1);
    
    board[i][j]=word[index];
    
    return result;
}

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int r=board.size();
        int c=board[0].size();
        char x=word[0];
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==x&&dfs(i,j,board,word,0))
                return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends