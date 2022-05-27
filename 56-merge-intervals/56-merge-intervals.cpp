class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
{
    if(a[0]==b[0])
    return a[1]<b[1];
    
    return a[0]<b[0];
}
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
             int n=intervals.size();
         vector<vector<int>> ans;
         int x,j;
         
         sort(intervals.begin(),intervals.end(),comp);
         
         x=intervals[0][0];
         j=intervals[0][1];
         
         for(int i=1;i<intervals.size();i++)
         {
             
             if(j>intervals[i][0]&&j>=intervals[i][1])
             continue;
             
            else if(j>=intervals[i][0]&&j<=intervals[i][1])
             {
             j=intervals[i][1];
             continue;
             }
         
         else
         {
             ans.push_back({x,j});
             x=intervals[i][0];
             j=intervals[i][1];
         }
             
         }
         
         
         ans.push_back({x,j});
         
         return ans;
    }
};