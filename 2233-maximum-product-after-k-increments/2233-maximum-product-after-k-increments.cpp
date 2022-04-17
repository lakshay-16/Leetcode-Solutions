class Solution {
public:
    long long int mod=10e9+7;
    
    int maximumProduct(vector<int>& nums, int k) {
        
         priority_queue<int,vector<int>,greater<int>>pq;  
        long long ans=1;
        for(auto val:nums){
            pq.push(val);
        }
        while(k>0){
            int t=pq.top()+1;
            pq.pop();
            pq.push(t);
            k--;
        }
        while(!pq.empty()){
            int t=pq.top();
            ans=(ans*t)%(1000000007);
            pq.pop();
        }
        return ans;
    }
};