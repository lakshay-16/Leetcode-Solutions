class BrowserHistory {
public:
    stack<string> future;
    stack<string> past;
    BrowserHistory(string homepage) {
        past.push(homepage);
    }
    
    void visit(string url) {
        past.push(url);
        
        while(!future.empty())
            future.pop();
    }
    
    string back(int steps) {
        
        while(steps>0&&past.size()>1)
        {
            string x=past.top();
            past.pop();
            future.push(x);
            steps--;
        }
        
        return past.top();
    }
    
    string forward(int steps) {
        
        while(!future.empty()&&steps>0)
        {
            string x=future.top();
            past.push(x);
            future.pop();
            steps--;
        }
        
        return past.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */