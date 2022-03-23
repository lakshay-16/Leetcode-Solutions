class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int sh=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]<prices[i-1])
            {
                profit+=prices[i-1]-sh;
                sh=prices[i];
            }
            
        }
        
        profit+=prices[prices.size()-1]-sh;
        
        
        return profit;
    }
};