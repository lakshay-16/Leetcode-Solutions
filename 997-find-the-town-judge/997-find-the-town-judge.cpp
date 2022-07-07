class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        
        for(int i=0;i<trust.size();i++)
            indegree[trust[i][0]]++;
        
     
        for(int i=0;i<trust.size();i++)
            outdegree[trust[i][1]]++;
     
        
        for(int i=1;i<n+1;i++)
            if(indegree[i]==0&&outdegree[i]==n-1)
                return i;
        
        return -1;
    }
};