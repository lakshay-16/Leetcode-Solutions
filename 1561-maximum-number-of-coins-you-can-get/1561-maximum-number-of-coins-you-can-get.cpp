class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        int n=piles.size();
        int first=0;
        int second=1;
        int last=n-1;
        sort(piles.rbegin(),piles.rend());
        int ans=0;
        
        while(second<last)
        {
            ans+=piles[second];
            first=second+1;
            second=first+1;
            
            last--;
        }
        
        
        return ans;
    }
};