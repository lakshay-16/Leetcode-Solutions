class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size()==1)
            return 0;
        
        int n=prices.size();
       vector<int> maxsofar;
        int ans=INT_MIN;
        
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            maxsofar.push_back(maxi);
        }
        
        reverse(maxsofar.begin(),maxsofar.end());
        
        for(int i=0;i<n-1;i++)
        {
            ans=max(maxsofar[i]-prices[i],ans);
        }
        
        return ans;
    }
};