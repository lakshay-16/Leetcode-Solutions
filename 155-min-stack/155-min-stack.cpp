class MinStack {
public:
    stack<int> s;
    int mini=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        mini=min(mini,val);
    }
    
    void pop() {
          if(s.top()!=mini)
           s.pop();
           
           else
           {
               s.pop();
               stack<int> p;
               mini=INT_MAX;
               while(!s.empty())
               {
                   mini=min(mini,s.top());
                   p.push(s.top());
                   s.pop();
               }
               
               while(!p.empty())
               {
                   s.push(p.top());
                   p.pop();
               }
           }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */