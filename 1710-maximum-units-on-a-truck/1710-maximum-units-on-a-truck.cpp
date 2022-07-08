class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return (a[1]<b[1]);
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int i=truckSize;
        int e=boxTypes.size()-1;
        int ans=0;
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        while(i>0&&e>=0)
        {
            if(boxTypes[e][0]>i)
                ans+=boxTypes[e][1]*i;
            
            else
            ans+=boxTypes[e][0]*boxTypes[e][1];
            
            i-=boxTypes[e][0];
            e--;
        }
        
        return ans;
    }
};