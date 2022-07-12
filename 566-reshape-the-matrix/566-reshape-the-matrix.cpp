class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(r*c!=mat.size()*mat[0].size())
            return mat;
        
        queue<int> pq;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
                pq.push(mat[i][j]);
        }
        
        vector<vector<int>> m(r,vector<int> (c,0));
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                m[i][j]=pq.front();
                pq.pop();
            }
        }
        
        return m;
    }
};