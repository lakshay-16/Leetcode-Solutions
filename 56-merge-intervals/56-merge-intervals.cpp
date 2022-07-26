class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]<b[1];
        
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        
        sort(intervals.begin(),intervals.end(),comp);
        
         int start=intervals[0][0];
        int end=intervals[0][1];
        
        
        for(int i=1;i<intervals.size();i++)
        {
            if(end>=intervals[i][1])
                continue;
            
            else if(end>=intervals[i][0])
            {
                end=intervals[i][1];
                continue;
            }
          
            else
            {
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        
        ans.push_back({start,end});
        
        return ans;
    }
};