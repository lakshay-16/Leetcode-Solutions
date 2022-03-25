class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
    
        
        int n=deck.size();
        int index=0;
        int flag=1;
        queue<int> pq;
        vector<int> ans(n);
        sort(deck.begin(),deck.end());
        
        for(int i=0;i<n;i++)
            pq.push(i);
    
        
        while(!pq.empty())
        {
            if(flag==1)
            {
                ans[pq.front()]=deck[index++];
                pq.pop();
            }
            
            else
            {
                pq.push(pq.front());
                pq.pop();
            }
            
            flag ^=1;
        }
        
        
        return ans;
    }
};