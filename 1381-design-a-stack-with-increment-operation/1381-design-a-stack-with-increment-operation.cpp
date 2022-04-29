class CustomStack {
public:
    int g[1000];
    int count=-1;
    int cap;
    CustomStack(int maxSize) {
        cap=maxSize;
    }
    
    void push(int x) {
        if(count>=cap-1)
            return;
        
           count++;
        g[count]=x;
    }
    
    int pop() {
        if(count==-1)
            return count;
        
        int p=count;
        
        count--;
        
        return g[p];
    }
    
    void increment(int k, int val) {
        
        for(int i=0;i<k&&i<=count;i++)
            g[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */