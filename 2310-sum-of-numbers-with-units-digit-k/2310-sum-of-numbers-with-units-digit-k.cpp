class Solution {
public:
    int solve(int index,int sum,vector<int> &g,vector<vector<int>> &dp)
    {
           if(sum==0)
            return 0;
        
       if(index<0)
           return 1e9;
        
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        
        int take=1e9;
        int nottake=solve(index-1,sum,g,dp);
        
        if(g[index]<=sum)
            take=1+solve(index,sum-g[index],g,dp);
        
        return dp[index][sum]=min(take,nottake);
    }
    
    int minimumNumbers(int num, int k) {
        
       
        
        if(num==0)
            return 0;
        
        if(num==k)
            return 1;
        
        if(num<k)
            return -1;
        
        
        vector<int> g;
        for(int i=1; i<=num; i++){
            if(i%10 == k)
                g.push_back(i);
        }       
        
          int n=g.size();
        vector<vector<int>> dp(n,vector<int> (num+1,-1));
        
      
        int ans=solve(n-1,num,g,dp);
        
        return (ans==1e9)?-1:ans;
    }
};