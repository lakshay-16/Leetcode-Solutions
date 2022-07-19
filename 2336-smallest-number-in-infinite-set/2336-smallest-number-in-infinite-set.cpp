class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int vis[1001];
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++)
        {pq.push(i);
         vis[i]=1;
        }
    }
    
    int popSmallest() {
        int y=pq.top();
        pq.pop();
        vis[y]=0;
        return y;
    }
    
    void addBack(int num) {
        if(vis[num]==0)
        {pq.push(num);
         vis[num]=1;
        }
    
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */