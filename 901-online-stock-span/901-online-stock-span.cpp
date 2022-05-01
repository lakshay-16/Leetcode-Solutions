class StockSpanner {
public:
    stack<pair<int,int>> st;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int a) {
     
        int ans = 1;
        if(st.empty()) ans = 1;
        else if(st.size() > 0 && st.top().first > a) ans = 1;
        else if(st.size() > 0 && st.top().first <= a) {
            while(!st.empty() && st.top().first <= a) { st.pop(); }
            if(st.empty()) ans = i+1;
            else ans = i - st.top().second;
        }
        st.push({a, i++});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */