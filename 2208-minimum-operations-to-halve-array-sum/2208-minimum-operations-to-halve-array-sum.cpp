# define d double

class Solution {
public:
    int halveArray(vector<int>& nums) {
       priority_queue<d> pq;
        d req=0;
        d sum=0;
        for(auto x:nums)
        {
            sum+=x;
            pq.push(x);
        }
      
        req=sum/2;
        int ans=0;
        
        while(sum>req)
        {
            d top=pq.top();
            pq.pop();
            
            top/=2;
            sum-=top;
            pq.push(top);
            ans++;
        }
        
        return ans;
    }
};