class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int ans=0;
        int g1=0,g2=1;
        int n=grades.size();
        
        while(g1<=n)
        {
            if(n-g1<g2)
                break;
            
            ans++;
            g1+=g2++;
        }
        
        return ans;
    }
};