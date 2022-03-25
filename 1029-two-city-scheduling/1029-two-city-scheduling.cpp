class Solution {
public:
    
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        return a.second<b.second; 
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n=costs.size();
        int ans=0;
        vector<pair<int,int>> m;
        for(int i=0;i<costs.size();i++)
        {
            m.push_back({i,costs[i][0]-costs[i][1]});
        }
        
        sort(m.begin(),m.end(),comp);
       
        for(int i=0;i<m.size();i++)
        {
            if(i<m.size()/2)
            ans+=costs[m[i].first][0];
                
            else
              ans+=costs[m[i].first][1];   
        }
        
        return ans;
    }
};