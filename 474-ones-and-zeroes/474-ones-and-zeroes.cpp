class Solution {
public:
    int dp[601][101][101];
    
     int solve(int m,int n,int index,vector<pair<int,int>> &ele)
    {
        if(index==0)
        {
            if(ele[0].first<=m&&ele[0].second<=n)
                return 1;
            
            return 0;
        }
        
        if(dp[index][m][n]!=-1)
            return dp[index][m][n];
            
        int nottake=0+solve(m,n,index-1,ele);
        int take=INT_MIN;
        
        if(ele[index].first<=m&&ele[index].second<=n)
            take=1+solve(m-ele[index].first,n-ele[index].second,index-1,ele);
        
        return dp[index][m][n]=max(take,nottake);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int i=strs.size();
        vector<pair<int,int>> elements;
        for(auto x:strs)
        {
            int one=0,zero=0;
            for(int i=0;i<x.length();i++)
            {
                if(x[i]=='1')
                    one++;
                
                else
                    zero++;
            }
            
            elements.push_back({zero,one});
        }
        
        
        memset(dp,-1,sizeof(dp));
        
        return solve(m,n,i-1,elements);
    }
};