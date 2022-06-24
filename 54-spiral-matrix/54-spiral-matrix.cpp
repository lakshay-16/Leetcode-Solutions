class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> ans;
        int sr=0;
        int er=matrix.size()-1;
        int sc=0;
        int ec=matrix[0].size()-1;
        int num=matrix.size()*matrix[0].size();
        int count=0;
        
        while(sr<=er&&sc<=sr)
        {
            for(int i=sc;i<=ec;i++)
            {
                ans.push_back(matrix[sr][i]);
                count++;
            }
            
            
            if(count==num)
                break;
            
              sr++;
            
            for(int i=sr;i<=er;i++)
            {
                ans.push_back(matrix[i][ec]);
                count++;
            }
            
             
            if(count==num)
                break;
            
             ec--;
            
            
            for(int i=ec;i>=sc;i--)
            {
                ans.push_back(matrix[er][i]);
                count++;
            }
            
             
            if(count==num)
                break;
            
             er--;
            
             for(int i=er;i>=sr;i--)
            {
                ans.push_back(matrix[i][sc]);
                 count++;
            }
            
             
            if(count==num)
                break;
            
            sc++;
            
        }
        
        return ans;
    }
};