class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001];
        dp[0]=cost[0];
        dp[1]=cost[1];
        
        for(int i=2;i<cost.size();i++)
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        
        int y=cost.size();
        return min(dp[y-1],dp[y-2]);
    }
};