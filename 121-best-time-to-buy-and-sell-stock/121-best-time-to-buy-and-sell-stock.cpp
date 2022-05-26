class Solution {
public:
    
    
    int maxProfit(vector<int>& prices) {
   
        if(prices.size()==1)
            return 0;
        
        int profit=-1;
        vector<int> ans;
    int n=prices.size();
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(maxi>prices[i])
                ans.push_back(maxi);
            
            else
            {
                ans.push_back(-1);
                maxi=prices[i];
            }
        }
            
        reverse(ans.begin(),ans.end());        
        
        for(int i=0;i<n-1;i++)
        {
            int dif;
            if(ans[i]==-1)
                dif=0;
            
            else
                dif=ans[i]-prices[i];
            
            profit=max(profit,dif);
        }
        
        return profit;
    }
};