class Solution {
public:
    
    bool dfs(vector<vector<char>> &board,int row,int column,string &word,int index)
    {
        if(row < 0 || row >= board.size() || column < 0 || column >= board[0].size() || board[row][column] != word[index])
        {
            return false;
        }
        
        if(index == word.length() - 1)
        {
            return true;
        }
        
        board[row][column] = '#';
        
        bool result = dfs(board, row-1, column, word, index+1);
        result = result || dfs(board, row, column-1, word, index+1);
        result = result || dfs(board, row+1, column, word, index+1);
        result = result || dfs(board, row, column+1, word, index+1);
        
        board[row][column] = word[index];
        
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {   
        int r=board.size();
        int c=board[0].size();
        char x=word[0];
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]==x&&dfs(board,i,j,word,0))
                {
                    return true;
                }
            }
        }
        
        
        
        return false;
    }
};