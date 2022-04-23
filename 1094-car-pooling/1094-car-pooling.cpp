class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       
        int total=-1;
        for(int i=0;i<trips.size();i++)
            total=max(total,trips[i][2]);
        
        vector<int> pass(total+1,0);
        
        for(vector<int> arr:trips)
        {
            pass[arr[1]]+=arr[0];
            
            pass[arr[2]]+=arr[0]*-1;
        }
        
        for(int i=1;i<pass.size()-1;i++)
        {
            pass[i]+=pass[i-1];
        }
        
        
        for(auto x:pass)
        {
            if(x>capacity)
                return false;
        }
        
        return true;
    }
};