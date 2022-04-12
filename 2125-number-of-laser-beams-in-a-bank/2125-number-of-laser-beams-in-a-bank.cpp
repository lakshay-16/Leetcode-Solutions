class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int n=bank.size();
        vector<int> dev(n);
        
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<bank[i].length();j++)
            if(bank[i][j]=='1')
                count++;
            
            if(count>0)
                dev.push_back(count);
        }
        
        int x=dev.size();
        int beam=0;
        
        for(int i=0;i<x-1;i++)
        {
            beam+=dev[i]*dev[i+1];
        }
        
        
        return beam;
    }
};