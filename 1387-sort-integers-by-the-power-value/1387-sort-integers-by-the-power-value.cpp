class Solution {
public:
    
    static bool comp(pair<int,long long> &a,pair<int,long long> &b)
    {
        if(a.second==b.second)
           return a.first<b.first;
        
        return a.second<b.second;
    }
    
    long long steps(int n)
    {
        long long s=0;
        
        while(n!=1)
        {
            if(n%2!=0)
                n=(3*n)+1;
            
            else
                n/=2;
            
            s++;
        }
        
        
        return s;
    }
    
    int getKth(int lo, int hi, int k) {
        
        vector<pair<int,long long>> g;
        
        for(int i=lo;i<=hi;i++)
        {
            long long x=steps(i);
            g.push_back({i,x});
        }
        
        sort(g.begin(),g.end(),comp);
        
        return g[k-1].first;
        
    }
};