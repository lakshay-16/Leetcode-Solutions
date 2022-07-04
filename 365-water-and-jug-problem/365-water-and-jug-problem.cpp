class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        
        int x=jug1Capacity;
        int y=jug2Capacity;
        int z=x+y;
        
        vector<int> vis(z+1,0);
        queue<int> pq;
        pq.push(0);
        vis[0]=1;
        vector<int> dx={x,-x,y,-y};
        
        while(!pq.empty())
        {
            int node=pq.front();
            pq.pop();
            
            if(node==targetCapacity)
                return true;
            
            for(int i=0;i<4;i++)
            {
                int cx=node+dx[i];
                
                if(cx>=0&&cx<=z&&!vis[cx])
                {   vis[cx]=1;
                    pq.push(cx);
                }
            
        }
    }
        
     return false;   
    }
};