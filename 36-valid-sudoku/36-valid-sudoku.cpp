class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
      vector<set<int>> rows(9),columns(9),boards(9);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                
                if(board[i][j]=='.')
                    continue;
                
                int n=board[i][j]-'0';
                
                if(rows[i].count(n)||columns[j].count(n)||boards[(i/3)*3+j/3].count(n))
                    return false;
                
                rows[i].insert(n);
                columns[j].insert(n);
                boards[(i/3)*3+j/3].insert(n);
            }
        }
        
        return true;
    }
};