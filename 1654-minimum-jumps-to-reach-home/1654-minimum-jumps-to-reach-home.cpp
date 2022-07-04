class Solution {
public:  
    unordered_map<int,int> m;
    int dp[6001][2];
    
    int solve(int i,int a,int b,int x,bool back)
    {
        if(i==x)
            return 0;
        
        if(i<0||i>6000||m.find(i)!=m.end()||back>=2)
            return 1e9;
        
        if(dp[i][back]!=-1)
            return dp[i][back];
        
        dp[i][back]=1+solve(i+a,a,b,x,0);
        
        if(!back)
        {
            dp[i][back]=min(dp[i][back],1+solve(i-b,a,b,x,1));
        }
            
        return dp[i][back];
    }
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
       
        for(int i=0;i<forbidden.size();i++)
            m[forbidden[i]]++;
        
        memset(dp,-1,sizeof(dp));
        int ans=solve(0,a,b,x,0);
        
        if(ans>=1e9)
            return -1;
        
        return ans;
    }
};